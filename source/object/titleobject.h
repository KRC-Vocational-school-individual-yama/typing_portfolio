#pragma once
#include"../libs/frameWork/object.h"

class TitleObject :public Object {
public:
	TitleObject(Scene* sc)	;
	~TitleObject()	override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

	/// <summary>
	/// 終了するキーを押したか
	/// </summary>
	/// <param name="true	">押した</param>
	/// <param name="false	">押してない</param>
	/// <returns></returns>
	bool EndKeyInput()		;

private:
	bool keystop;
	bool mouseInput;
	int hFont;
};