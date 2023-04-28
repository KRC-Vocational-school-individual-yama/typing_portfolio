#pragma once
#include"../libs/frameWork/myDxLib.h"
#include<list>

class Effect {
public:
	Effect();
	~Effect();
	void Init();
	void Update();
	void Draw();

	void CreateEffect(VECTOR pos,VECTOR vec);
private:
	struct Particle {

		VECTOR pos;
		VECTOR vec;
		float rad;

		void DrawSphere3D(unsigned int DifColor, unsigned int SpcColor, int FillFlag)const {
			DxLib::DrawSphere3D(pos,rad,21,DifColor,SpcColor,FillFlag);
		}
	};
	std::list<Particle> effectList;
};