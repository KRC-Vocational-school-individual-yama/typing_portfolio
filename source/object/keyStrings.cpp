#include "keyStrings.h"
#include"../libs/frameWork/scenemanager.h"
#include"loadcsv.h"
#include"effect.h"

namespace {
	static const int TEXT_MAX = 50;//入力の最大文字数
	static const int TEXT_HEIGHT_MAX = 5;
	static char SAMPLE_STRINGS[TEXT_HEIGHT_MAX][TEXT_MAX] =
	{
		{"typinggame" }
		,{"aaa"}
		,{"bbb"}
		,{"ccc"}
		,{"ddd"}
	};
	static char SAMPLE_STRINGS_VIEW[TEXT_HEIGHT_MAX][TEXT_MAX] =
	{
		{"タイピングゲーム" }
		,{"あああ"}
		,{"bbb"}
		,{"ccc"}
		,{"ddd"}
	};
	Effect* effect;
}

KeyStrings::KeyStrings(Scene* sc)
	:Object(sc)
	,inputList()
	,sampleString()
	,sampleStringView()
	,sampleStringNum{0}
	,textHeightMax{0}
	,ok{false}
{}

KeyStrings::~KeyStrings(){

}

void KeyStrings::Init(){
	GetInputChar(TRUE);

	LoadCsv* csvP= GetScene()->Invoke<LoadCsv>();
	if (csvP) {
		csvP->Load();
		int maxIndex = csvP->GetTextMax();
		for (int i = 0; i < maxIndex; i++) {
			std::string str =csvP->GetText(i,0);
			sampleString.emplace_back(str);
			str =csvP->GetText(i,1);
			sampleStringView.emplace_back(str);
		}
	}

	//もし、ファイルがなかった場合
	if (sampleString.empty()) {
		sampleString.resize(TEXT_HEIGHT_MAX, "");
		sampleStringView.resize(TEXT_HEIGHT_MAX, "");
		for (int i = 0; i < TEXT_HEIGHT_MAX; i++) {
			sampleString.at(i) = std::string(SAMPLE_STRINGS[i]);
			sampleStringView.at(i) = std::string(SAMPLE_STRINGS_VIEW[i]);
		}
		
		//ファイルに無いのでセットする
		std::vector<std::string> send;
		for (int i = 0; i < TEXT_HEIGHT_MAX; i++) {
			send.emplace_back(sampleString.at(i));
			send.emplace_back(sampleStringView.at(i));
		}
		csvP->SetText(send);
	}


	textHeightMax = csvP->GetTextMax();
	effect = new Effect;
	effect->Init();
}

void KeyStrings::Update(){
	ok = false;
	char getKey = GetInputChar(TRUE);
	bool hitKeyString = getKey != 0 && getKey >= CTRL_CODE_CMP;

	if (hitKeyString) {

		std::string sendS(&getKey, &getKey + 1);
		if (sendS != " " && inputList.size() <= TEXT_MAX)
			inputList.emplace_back(OneString{ sendS,0x0 });
	}

	// backSpaceで消す
	if (getKey == CTRL_CODE_BS) {

		bool inNotSuccess = false;
		for (const auto& input : inputList) {
			if (!input.isSuccess) {
				inNotSuccess = true;
				break;
			}
		}

		if (!inputList.empty()
			&& inNotSuccess
			)
			inputList.pop_back();
	}
	if (getKey == CTRL_CODE_CR) {
		inputList.clear();

		for (int i = 0; i < sampleString.at(sampleStringNum).size(); i++) {
			char temp = sampleString.at(sampleStringNum).at(i);
			std::string sendStr(&temp, &temp + 1);

			OneString send;
			send.str = sendStr;
			send.isSuccess = true;

			inputList.emplace_back(send);
		}
	}

	// 文字比較
	std::string inputS = "";
	for (const auto& one : inputList) {
		const auto& s = one.str;
		inputS += s;
	}
	//１文字比較
	for (int i = 0; i < inputS.size(); i++) {
		const auto& one = inputS.at(i);
		if (sampleString.at(sampleStringNum).size() <= i) {
			inputList.at(i).col = 0xff0000;
			inputList.at(i).isSuccess = false;

			continue;
		}

		if (sampleString.at(sampleStringNum).at(i) != one) {
			inputList.at(i).isSuccess = false;
			inputList.at(i).col = 0xff00000;
		}
		else {
			inputList.at(i).isSuccess = true;
			inputList.at(i).col = 0x0;
		}
	}

	//文字が全て合っているか
	if (sampleString.at(sampleStringNum) == inputS) {
		ok = true;
		inputList.clear();
		sampleStringNum = (std::min)(sampleStringNum + 1, textHeightMax - 1);
	}
	if (hitKeyString) {
		if(!inputList.empty()){
			unsigned int inputListIndex = inputList.size() - 1;
			
			if (inputList.at(inputListIndex).isSuccess) {

				VECTOR pos = VGet(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
				VECTOR vec = VGet(0,0,25)* MGetRotX(DX_PI * -45.f / 180.f) * MGetRotY(DX_PI * GetRand(360.f)/180.f );
				effect->CreateEffect(pos,vec);
			}
		}
	}


	effect->Update();
}

void KeyStrings::Draw(){
	effect->Draw();



	int x = SCREEN_WIDTH/2;
	int y = SCREEN_HEIGHT/2;
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	DrawString(x,y,sampleString.at(sampleStringNum).c_str(),0x0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	
	
	int widthDistance = GetDrawStringWidth("a", 1);
	int heightSize = GetFontSize();
	// 入力した文字
	for(int i=0;i<inputList.size();i++){
	//for (const auto& one : inputList) {
		const auto& one = inputList.at(i);
		const auto& s = one.str;

		int dispX = x + i * widthDistance;
		DrawString(dispX,y,s.c_str(),one.col);
		DrawBox(dispX, y+heightSize, dispX + widthDistance,y+heightSize+10,0x0,false);
	//	x += widthDistance;
	}

	// 指定文字
	DrawString(x, y - (heightSize *3), sampleStringView.at(sampleStringNum).c_str(), 0x0);

	// 文字があってたら　表示
	if (ok) {
		DrawCircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,36,0x0,false);
	}

}
