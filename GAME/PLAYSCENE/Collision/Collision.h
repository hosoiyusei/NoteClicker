#pragma once
#include"../../Utility.h"

//�~�̔���p�\����
struct CircleCollider
{
	//�ϐ�=====================================

	//���a
	float mRadius;

	//���W
	Float2 mPos;

	//�֐�======================================

	//�ق��̉~�Ƃ̓����蔻��
	BOOL CheckHit(CircleCollider collider);
};