#include "loadcsv.h"
#include"../libs/common/save.h"

namespace {
	std::string filePass = "data/textData/";
	std::string folder = "typeText.txt";

}

LoadCsv::LoadCsv(Scene* sc)
	:Object(sc)
	,textList()
{}

LoadCsv::~LoadCsv(){
	Save();
}

void LoadCsv::Init(){
	Load();
	

}

void LoadCsv::Update(){

}

void LoadCsv::Draw(){

}

std::string LoadCsv::GetText(int column, int row){

	return textList.at(column*2+row);
}

void LoadCsv::Load(){
	textList = CsvSave::Load((filePass + folder).c_str());




}

void LoadCsv::Save(){
	CsvSave::Save((filePass+folder).c_str(),textList,2);

}
