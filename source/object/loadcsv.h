#pragma once
#include"../libs/frameWork/object.h"
#include<string>
#include<vector>

class LoadCsv :public Object {
public:
	LoadCsv(Scene*sc);
	~LoadCsv()override;
	void Init()override;
	void Update()override;
	void Draw()override;
	void SetText(std::vector<std::string>data) { textList = data; }
	std::string GetText(int column, int row);
	int GetTextMax() { return textList.size() / 2; }
	void Load();
	void Save();
private:
	//struct CsvFile {
	//	std::vector<std::string> rowText;
	//};
	//std::vector<CsvFile>textList;

	std::vector<std::string> textList;

};


