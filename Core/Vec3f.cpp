/*
 * Vec3f.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: hakosoft
 */

#include "Vec3f.h"

namespace RP {

/*********************************************************************
 *
 *  defining the constractors  all 4 of them
 *
 ********************************************************************/
Vec3f::Vec3f()
{
	Zeros();
}


Vec3f::Vec3f(float s) // create  vector with one number like s = 5 ou V will be (5,5)
{
	x = s;
	y = s;
	z = s;
}

Vec3f::Vec3f(float a, float b,float c) // create a vector from 2 numbers a,b our vector will look like v (a, b)
{
	x = a;
	y = b;
	z = c;
}

Vec3f::Vec3f(Vec3f &v) // create a vector from an other vector
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vec3f::~Vec3f()
{
	// Do nothing
}

/*****************************************************************
 *
 * the get and set function
 *
 ****************************************************************/


float Vec3f::getX()
{
	return this->x;
}

void Vec3f::setX(float s)
{
	 this->x  =  s;
}

float Vec3f::getY()
{
	return this->y;
}

void Vec3f::setY(float s)
{
	this->y = s;
}

float Vec3f::getZ()
{
	return this->z;
}

void Vec3f::setZ(float s)
{
	this->z = s;
}
void Vec3f::Ones()
{
	this->x = 1;
	this->y = 1;
	this->z = 1;
}

void Vec3f::Zeros()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
/****************************************************************
 * Overloading oprators
 ***************************************************************/

float& Vec3f::operator [] (int i)
{
	assert(i >= 0); // make sure everthing is ok with indexing
	return *(&x + i);
}

Vec3f Vec3f::operator -() const
{
	Vec3f Nigative(-x,-y,-z);

	return Nigative;
}

Vec3f Vec3f::operator +(Vec3f a)
{
	Vec3f R;
	R.x = this->x + a.x;
	R.y = this->y + a.y;
	R.z = this->z + a.z;

   return R;
}

Vec3f Vec3f::operator +(float s)
{
	Vec3f R;
	R.x = this->x + s;
	R.y = this->y + s;
	R.z = this->z + s;
   return R;
}

Vec3f Vec3f::operator -(Vec3f a)
{
	Vec3f R;
	R.x = this->x - a.x;
	R.y = this->y - a.y;
	R.z = this->z - a.z;

   return R;
}

Vec3f Vec3f::operator -(float s)
{
	Vec3f R;
	R.x = this->x - s;
	R.y = this->y - s;
	R.z = this->z - s;

   return R;
}
Vec3f Vec3f::operator *(Vec3f a)
{
	Vec3f R;
	R.x = this->x * a.x;
	R.y = this->y * a.y;
	R.z = this->z * a.z;

	return R;
}

Vec3f Vec3f::operator *(float s)
{
	Vec3f R;
	R.x = this->x * s;
	R.y = this->y * s;
	R.z = this->z * s;

   return R;
}


Vec3f Vec3f::operator /(float s)
{
	Vec3f R;
	R.x = this->x / s;
	R.y = this->y / s;
	R.z = this->z / s;

   return R;
}

} /* namespace RP */
