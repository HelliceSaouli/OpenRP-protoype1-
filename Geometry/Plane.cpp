/*
 * Plane.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft
 */

#include <Plane.h>

namespace RP
{

	Plane::Plane()
	{
		this->position = Vec4f(0.0,0.0,0.0,1.0);
		this->normal   = Vec4f(0.0,1.0,0.0,0.0);
		this->color    = Color::white;
	}

	Plane::Plane(const Vec4f &p, const Vec4f &n, const Color &c) // simple constractor takes a postion and normal vector
	{
		this->position = p;
		this->normal   = n;
		this->color    = c;

	}

	Plane::~Plane()
	{
		// TODO Auto-generated destructor stub
	}


	/*************************************************
	 * set and get                                   *
	 *************************************************/

   void Plane::setPosition(const Vec4f &position)
   {
	   this->position = position;
   }

   void Plane::setNormal(const Vec4f &normal)
   {
	   this->normal = normal;
   }

   Vec4f Plane::getPosition()const
   {
	   return this->position;
   }

   Vec4f Plane::getNormal()const
   {
	   return this->normal;
   }

   Color Plane::ObjectColor()
   {
	   return this->color;
   }

   /***************************************************
    * most fun par is here XD the god dm intersection *
    ***************************************************/

   float Plane::intersection(const Ray &ray)
   {
	   // first of all we check if the ray is not prependicular with  the normal of plane if so there is no intersection
	   Vec4f RayOrigine   = ray.getOrigine();
	   Vec4f RayDirection = ray.getDirection();

	   float check = Dot(this->normal, RayDirection);

	   if(check == 0)
	   {
		   //there is no intersection will return a rubich not a number value
		   return NAN;
	   }
	   else
	   {
		   // there is intersection we will put the paramitric representation of the ray
		   // in the implicite representation of the plane and we solve the équation for t
		   // t = -1 * (n.(o - p0) / n.d. there is  alwz one solution when ray cross the
		   // plane
		   float t = -1 * (Dot(this->normal,(RayOrigine - this->position)) / Dot(this->normal,RayDirection));
		   if( t > 0 )
		     return t;
		   else
			   return NAN; // intersection bihind the scene;
	   }
   }
} /* namespace RP */
