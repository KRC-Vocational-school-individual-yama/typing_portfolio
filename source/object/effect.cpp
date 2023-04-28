#include "effect.h"

Effect::Effect()
	:effectList()
{}

Effect::~Effect(){

}

void Effect::Init(){
	//for (int i = 0; i < 10; i++) {
	//	CreateEffect(VGet(0,0,0),VGet(0,0,0));
	//}

}

void Effect::Update(){
	if (effectList.empty())
		return;



	for (Particle& effe : effectList) {
		effe.vec = VAdd(effe.vec, VGet(0,-1.5f,0));

		effe.pos = VAdd(effe.pos, effe.vec);
		


	}
}

void Effect::Draw(){
	if (effectList.empty())
		return;

	for (const Particle& effe : effectList) {
		effe.DrawSphere3D(0xffffff,0xffffff,TRUE);
	}
}

void Effect::CreateEffect(VECTOR pos, VECTOR vec){
	Particle emit;
	emit.pos = pos;
	emit.vec = vec;
	emit.rad = 50.f;

	effectList.emplace_back(emit);

}
