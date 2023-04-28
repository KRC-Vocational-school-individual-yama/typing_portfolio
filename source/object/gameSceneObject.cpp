#include "gameSceneObject.h"
#include"effect.h"

namespace {
	Effect* effect=nullptr;
}


GameSceneObject::GameSceneObject(Scene* sc)
	:Object(sc)
	,counter{0}
	,anser{0.f}
{

}

GameSceneObject::~GameSceneObject()
{
	delete effect;
}

void GameSceneObject::Init()
{
	effect = new Effect();
	effect->Init();
}

void GameSceneObject::Update()
{
	effect->Update();
	if(counter<=100)
	counter++;

	anser = EASEING::EInOutBack(counter);
}

void GameSceneObject::Draw()
{
	effect->Draw();

	//- - - - - - - - - - - - 
	return;
	//- - - - - - - - - - - - 


	Vec2 screenSize = {};
	GetDrawScreenSize(&screenSize.x,&screenSize.y);
	VECTOR pos=VGet(screenSize.x/2.f, screenSize.y/2.f,0);
	VECTOR size=VGet(50+anser,50 + anser,0);
	DrawBoxCenterVector(pos,size,0x0,TRUE);

	DrawFormatString(300,300,0x0,"%f",pos.x);
	DrawFormatString(300,320,0x0,"%f",anser);
}
