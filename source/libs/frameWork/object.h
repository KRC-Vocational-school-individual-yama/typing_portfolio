#pragma once

#include"myDxLib.h"

#include<string>
#include<list>
class Scene;
class Component;

class Object {
public:
	Object(Scene* sc)
		:myScene(sc)
		,myDestroy(false)
		,myStopUpdate(false)
	{}
	virtual ~Object(){}
	virtual void Init()		{}
	virtual void Update()	{}
	virtual void Draw()		{}


	/// <summary>
	/// 所属シーン取得
	/// </summary>
	/// <returns></returns>
	Scene* GetScene()			{ return myScene	;}



	/// <summary>
	/// 破棄フラグ　ゲッター
	/// </summary>
	/// <returns></returns>
	const bool GetDestroy()		{ return myDestroy	;}

	/// <summary>
	/// 更新停止フラグ　ゲッター
	/// </summary>
	/// <returns></returns>
	const bool GetStopUpdate() { return myStopUpdate; }

	/// <summary>
	/// 破棄フラグ　セッター
	/// </summary>
	/// <param name="_flag"></param>
	void MyDestroy()			{ myDestroy = true	;}

	/// <summary>
	/// 更新停止フラグ　セッター
	/// </summary>
	/// <param name="true	">stop</param>
	/// <param name="false	">start</param>
	/// <returns></returns>
	void SetMyUpdate(bool flag = false) { myStopUpdate = flag; }

private:

	Scene* myScene		;//所属シーン
	bool myDestroy		;//破棄フラグ
	bool myStopUpdate	;//更新停止フラグ true：停止
};
