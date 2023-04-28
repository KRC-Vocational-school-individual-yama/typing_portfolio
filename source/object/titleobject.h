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
	/// �I������L�[����������
	/// </summary>
	/// <param name="true	">������</param>
	/// <param name="false	">�����ĂȂ�</param>
	/// <returns></returns>
	bool EndKeyInput()		;

private:
	bool keystop;
	bool mouseInput;
	int hFont;
};