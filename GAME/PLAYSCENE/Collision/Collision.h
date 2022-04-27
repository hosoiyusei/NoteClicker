#pragma once
#include"../../Utility.h"

//円の判定用構造体
struct CircleCollider
{
	//変数=====================================

	//半径
	float mRadius;

	//座標
	Float2 mPos;

	//関数======================================

	//ほかの円との当たり判定
	BOOL CheckHit(CircleCollider collider);
};