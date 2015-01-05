/*
 * Vec2f.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: hakosoft
 */

#include "Vec2f.h"

namespace RP {

/*********************************************************************
 *
 *  defining the constractors  all 4 of them
 *
 ********************************************************************/
Vec2f::Vec2f()
{
	Zeros();
}


Vec2f::Vec2f(float s) // create  vector with one number like s = 5 ou V will be (5,5)
{
	x = s;
	y = s;
}

Vec2f::Vec2f(float a, float b) // create a vector from 2 numbers a,b our vector will look like v (a, b)
{
	x = a;
	y = b;
}

Vec2f::Vec2f(Vec2f &v) // create a vector from an othher vector
{
	x = v.x;
	y = v.y;
}

Vec2f::~Vec2f()
{
	// Do nothing
}

/*****************************************************************
 *
 * the get and set function
 *
 ****************************************************************/


float Vec2f::getX()
{
	return this->x;
}

void Vec2f::setX(float s)
{
	 this->x  =  s;
}

float Vec2f::getY()
{
	return this->y;
}

void Vec2f::setY(float s)
{
	this->y = s;
}

void Vec2f::Ones()
{
	this->x = 1;
	this->y = 1;
}

void Vec2f::Zeros()
{
	this->x = 0;
	this->y = 0;
}
/****************************************************************
 * Overloading oprators
 ***************************************************************/

float& Vec2f::operator [] (int i)
{
	assert(i >= 0); // make sure everthing is ok with indexing
	return *(&x + i);
}

Vec2f Vec2f::operator -() const
{
	Vec2f Nigative(-x,-y);

	return Nigative;
}

Vec2f Vec2f::operator +(Vec2f a)
{
	Vec2f R;
	R.x = this->x + a.x;
	R.y = this->y + a.y;

   return R;
}

Vec2f Vec2f::operator +(float s)
{
	Vec2f R;
	R.x = this->x + s;
	R.y = this->y + s;

   return R;
}

Vec2f Vec2f::operator -(Vec2f a)
{
	Vec2f R;
	R.x = this->x - a.x;
	R.y = this->y - a.y;

   return R;
}

Vec2f Vec2f::operator -(float s)
{
	Vec2f R;
	R.x = this->x - s;
	R.y = this->y - s;

   return R;
}
Vec2f Vec2f::operator *(Vec2f a)
{
	Vec2f R;
	R.x = this->x * a.x;
	R.y = this->y * a.y;

	return R;
}

Vec2f Vec2f::operator *(float s)
{
	Vec2f R;
	R.x = this->x * s;
	R.y = this->y * s;

   return R;
}


Vec2f Vec2f::operator /(float s)
{
	Vec2f R;
	R.x = this->x / s;
	R.y = this->y / s;

   return R;
}

} /* namespace RP */
