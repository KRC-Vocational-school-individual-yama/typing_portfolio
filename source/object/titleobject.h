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
	/// I—¹‚·‚éƒL[‚ğ‰Ÿ‚µ‚½‚©
	/// </summary>
	/// <param name="true	">‰Ÿ‚µ‚½</param>
	/// <param name="false	">‰Ÿ‚µ‚Ä‚È‚¢</param>
	/// <returns></returns>
	bool EndKeyInput()		;

private:
	bool keystop;
	bool mouseInput;
	int hFont;
};