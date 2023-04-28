#pragma once
#include"../frameWork/myDxLib.h"
#include<string>

class Button {
public:
	Button(const VECTOR& pos, const VECTOR& size, const std::string name,const bool sizeAuto=true);
	Button();
	~Button();
	void Draw(int Color, float LineThickness = 1.0f,int hFont=-1);
	// マウスとボタンの当たり判定
	bool OnCollision(const VECTOR& pos, const VECTOR& size) {
		return SquareCollision(pos, size, _pos, _size);
	}
	// マウスとボタンの当たり判定
	bool OnCollision() {
		Vec2 mouse;
		GetMousePoint(&mouse.x,&mouse.y);
		return OnCollision(VGet(mouse),VGet(5,5,0));
	}
	bool Click() {
		return OnCollision() && (GetMouseInput() & MOUSE_INPUT_LEFT);
	}
	std::string GetMyName() { return _name; }
	void GetTransform(VECTOR& pos, VECTOR& size) {
		pos = _pos;
		size = _size;
	}
private:
	VECTOR _pos;
	VECTOR _size;
	std::string _name;
	bool _sizeAuto;	
};


inline Button::Button(const VECTOR& pos, const VECTOR& size, const std::string name,const bool sizeAuto)
	:_pos(pos)
	, _size(size)
	, _name(name)
	,_sizeAuto(sizeAuto)
{}
inline Button::Button()
	:Button(VGet(0, 0, 0), VGet(0, 0, 0), "")
{}
inline Button::~Button() {

}
inline void Button::Draw(int Color, float LineThickness,int hFont) {
	if (_sizeAuto) {
		int fontSize	= -1;
		int len			= -1;
		if (hFont > 0) {
			fontSize = GetFontSizeToHandle(hFont);
			len = GetDrawFormatStringWidthToHandle(hFont,_name.c_str());
		}
		else {
			fontSize = GetFontSize();
			len = GetDrawFormatStringWidth(_name.c_str());
		}
		_size = VGet(len,fontSize,0);
		
	}

	DrawBoxAA(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, Color, false, LineThickness);
	
	
	if (hFont > 0) {
		float dispStringX = _pos.x + _size.x / 2 - GetDrawFormatStringWidthToHandle(hFont,_name.c_str()) / 2;
		float dispStringY = _pos.y + _size.y / 2 - GetFontSizeToHandle(hFont) / 2;

		DrawFormatStringFToHandle(dispStringX, dispStringY, Color,hFont, _name.c_str());
		return;
	}

	float dispStringX = _pos.x + _size.x / 2 - GetDrawFormatStringWidth(_name.c_str())/2;
	float dispStringY = _pos.y + _size.y / 2 - GetFontSize()/2;
	DrawFormatStringF(dispStringX, dispStringY, Color, _name.c_str());
}