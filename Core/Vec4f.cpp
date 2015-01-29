/*
 * Vec4f.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: hakosoft
 */

#include "Vec4f.h"

namespace RP {

/*********************************************************************
 *
 *  defining the constractors  all 4 of them
 *
 ********************************************************************/
Vec4f::Vec4f()
{
	Zeros();
}


Vec4f::Vec4f(float s) // create  vector with one number like s = 5 ou V will be (5,5)
{
	x = s;
	y = s;
	z = s;
	w = s;
}

Vec4f::Vec4f(float a, float b,float c,float d) // create a vector from 2 numbers a,b our vector will look like v (a, b)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

Vec4f::Vec4f(const Vec4f &v) // create a vector from an othher vector
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

Vec4f::~Vec4f()
{
	// Do nothing
}

/*****************************************************************
 *
 * the get and set function
 *
 ****************************************************************/


float Vec4f::getX() const
{
	return this->x;
}

void Vec4f::setX(float s)
{
	 this->x  =  s;
}

float Vec4f::getY() const
{
	return this->y;
}

void Vec4f::setY(float s)
{
	this->y = s;
}

float Vec4f::getZ() const
{
	return this->z;
}

void Vec4f::setZ(float s)
{
	this->z = s;
}

float Vec4f::getW() const
{
	return this->w;
}

void Vec4f::setW(float s)
{
	this->w = s;
}
void Vec4f::Ones()
{
	this->x = 1;
	this->y = 1;
	this->z = 1;
	this->w = 1;
}

void Vec4f::Zeros()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}
/****************************************************************
 * Overloading oprators
 ***************************************************************/

const float Vec4f::operator [] (int i)const
{
	assert(i >= 0); // make sure everthing is ok with indexing
	return *(&x + i);
}

float& Vec4f::operator [] (int i)
{
	assert(i >= 0); // make sure everthing is ok with indexing
	return *(&x + i);
}

Vec4f Vec4f::operator -() const
{
	Vec4f Nigative(-x,-y,-z,-w);

	return Nigative;
}

Vec4f Vec4f::operator +(const Vec4f &a) const
{
	Vec4f R;
	R.x = this->x + a.x;
	R.y = this->y + a.y;
	R.z = this->z + a.z;
	R.w = this->w + a.w;

   return R;
}

Vec4f Vec4f::operator +(const float s) const
{
	Vec4f R;
	R.x = this->x + s;
	R.y = this->y + s;
	R.z = this->z + s;
	R.w = this->w + s;
   return R;
}

Vec4f Vec4f::operator -(const Vec4f &a)const
{
	Vec4f R;
	R.x = this->x - a.x;
	R.y = this->y - a.y;
	R.z = this->z - a.z;
	R.w = this->w - a.w;

   return R;
}

Vec4f Vec4f::operator -(const float s)const
{
	Vec4f R;
	R.x = this->x - s;
	R.y = this->y - s;
	R.z = this->z - s;
	R.w = this->w - s;

   return R;
}
Vec4f Vec4f::operator *(const Vec4f &a)const
{
	Vec4f R;
	R.x = this->x * a.x;
	R.y = this->y * a.y;
	R.z = this->z * a.z;
	R.w = this->w * a.w;

	return R;
}

Vec4f Vec4f::operator *(const float s)const
{
	Vec4f R;
	R.x = this->x * s;
	R.y = this->y * s;
	R.z = this->z * s;
	R.w = this->w * s;

   return R;
}


Vec4f Vec4f::operator /(const float s) const
{
	Vec4f R;
	R.x = this->x / s;
	R.y = this->y / s;
	R.z = this->z / s;
	R.w = this->w / s;

   return R;
}

} /* namespace RP */
