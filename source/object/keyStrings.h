#pragma once
#include"../libs/frameWork/object.h"
#include<string>
#include<vector>

class KeyStrings :public Object {
public:
	KeyStrings(Scene* sc);
	~KeyStrings()override;
	void Init()override;
	void Update()override;
	void Draw()override;
private:
	enum class State {
		playerInput
		,stringCheck
		
	};

	struct OneString {
		std::string str="";
		int col=0x0;
		bool isSuccess=false;
	};

	std::vector<OneString>inputList;
	std::vector<std::string> sampleString;
	std::vector<std::string> sampleStringView;
	int sampleStringNum;
	int textHeightMax;
	bool ok;
	
};