#pragma once
#include"../libs/frameWork/object.h"

class GameSceneObject :public Object {
public:
	GameSceneObject(Scene* sc);
	~GameSceneObject()	override;
	void Init()override;
	void Update()override;
	void Draw()override;
private:
	int counter;
	float anser;

};
