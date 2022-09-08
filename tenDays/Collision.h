#pragma once
#include"Vec.h"
///<summary>
///当たり判定ヘルパークラス
///</summary>
class Collision
{
public:
	
	//2D当たり判定
	/// <summary>
	/// 円と円の当たり判定
	/// </summary>
	/// <param name="circle1">１つ目の円の中心位置</param>
	/// <param name="circle2">２つ目の円の中心位置</param>
	/// <param name="radius1">１つ目の円の大きさ</param>
	/// <param name="radius2">２つ目の円の大きさ</param>
	/// <returns></returns>
	static bool CircleCollision(Vec2 circle1, Vec2 circle2, float radius1, float radius2);

	static float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	/// <summary>
	/// 四角形と四角形
	/// </summary>
	/// <param name="box1">1つ目の四角形の位置</param>
	/// <param name="box2">２つ目の四角形の位置</param>
	/// <param name="size1">１つ目の四角形の大きさ</param>
	/// <param name="size2">２つ目の四角形の大きさ</param>
	/// <returns></returns>
	static bool BoxCollision(Vec2 box1, Vec2 box2, Vec2 size1, Vec2 size2);

	/// <summary>
	/// 円と四角形
	/// </summary>
	/// <param name="circle">円の位置</param>
	/// <param name="radius">円の大きさ</param>
	/// <param name="box">四角形の位置</param>
	/// <param name="size">四角形の大きさ</param>
	/// <returns></returns>
	static bool Circle2Box(Vec2 circle, float radius, Vec2 box, Vec2 size);

	//試し
	
	static bool CollisionTrinangle(Vec2 pPos, Vec2 box, Vec2 size,float angle);

};