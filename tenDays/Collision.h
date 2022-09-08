#pragma once
#include"Vec.h"
///<summary>
///�����蔻��w���p�[�N���X
///</summary>
class Collision
{
public:
	
	//2D�����蔻��
	/// <summary>
	/// �~�Ɖ~�̓����蔻��
	/// </summary>
	/// <param name="circle1">�P�ڂ̉~�̒��S�ʒu</param>
	/// <param name="circle2">�Q�ڂ̉~�̒��S�ʒu</param>
	/// <param name="radius1">�P�ڂ̉~�̑傫��</param>
	/// <param name="radius2">�Q�ڂ̉~�̑傫��</param>
	/// <returns></returns>
	static bool CircleCollision(Vec2 circle1, Vec2 circle2, float radius1, float radius2);

	static float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	/// <summary>
	/// �l�p�`�Ǝl�p�`
	/// </summary>
	/// <param name="box1">1�ڂ̎l�p�`�̈ʒu</param>
	/// <param name="box2">�Q�ڂ̎l�p�`�̈ʒu</param>
	/// <param name="size1">�P�ڂ̎l�p�`�̑傫��</param>
	/// <param name="size2">�Q�ڂ̎l�p�`�̑傫��</param>
	/// <returns></returns>
	static bool BoxCollision(Vec2 box1, Vec2 box2, Vec2 size1, Vec2 size2);

	/// <summary>
	/// �~�Ǝl�p�`
	/// </summary>
	/// <param name="circle">�~�̈ʒu</param>
	/// <param name="radius">�~�̑傫��</param>
	/// <param name="box">�l�p�`�̈ʒu</param>
	/// <param name="size">�l�p�`�̑傫��</param>
	/// <returns></returns>
	static bool Circle2Box(Vec2 circle, float radius, Vec2 box, Vec2 size);

	//����
	
	static bool CollisionTrinangle(Vec2 pPos, Vec2 box, Vec2 size,float angle);

};