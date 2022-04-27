#pragma once
#include"../../Utility.h"

//‰~‚Ì”»’è—p\‘¢‘Ì
struct CircleCollider
{
	//•Ï”=====================================

	//”¼Œa
	float mRadius;

	//À•W
	Float2 mPos;

	//ŠÖ”======================================

	//‚Ù‚©‚Ì‰~‚Æ‚Ì“–‚½‚è”»’è
	BOOL CheckHit(CircleCollider collider);
};