/*
 * Sphere.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft
 */

#include <Sphere.h>

namespace RP
{

	Sphere::Sphere()
	{
		this->Origine = Vec4f(0.0,0.0,0.0,1.0);
		this->raduis  = 1.0;
		this->color   = Color::red;
		this->Ks   = Color::black;
	}

	Sphere::Sphere(const Vec4f &o, float r, const Color &c)
	{
		this->Origine = o;
		this->raduis  = r;
		this->color   = c;
		this->Ks   = Color::black;
	}

	Sphere::~Sphere()
	{
		// TODO Auto-generated destructor stub
	}

	void Sphere::setOrigine(const Vec4f &o)
	{
		this->Origine = o;
	}

	Vec4f Sphere::getOrigine()const
	{
		return this->Origine;
	}

	float Sphere::getRaduis()const
	{
		return this->raduis;
	}

	Color Sphere::ObjectColor()
	{
		return this->color;
	}

	Vec4f Sphere::ObjectNormal_at(const Vec4f &point)const
	{

		// since it's sphere than every point in it has  it's own normal
		// that normal is simply the extention of line betewen the center
		// and the point

		Vec4f Normal = Normalize(point - this->Origine);
		return Normal;
	}

    void Sphere::setKa(const Color ka)
	   {
		   this->Ka = ka;
	   }

	void Sphere::setKs(const Color ks)
	   {
		   this->Ks = ks;
	   }

   void Sphere::setKd(const Color kd)
	   {
		   this->Kd = kd;
	   }

    Color Sphere::getKa()const
	   {
		   return this->Ka;
	   }

	Color Sphere::getKs()const
	   {
		   return this->Ks;
	   }

   Color Sphere::getKd()const
	   {
		   return this->Kd;
	   }

   bool Sphere::isShining()
   {
 	  if (this->Ks == Color::black)
 		  return false;
 	  else
 		  return true;
   }

	float Sphere::intersection(const Ray &ray)
	{

		// we have to solve the quadric equiation for t
		//(d · d)t² + 2d ·(e − c)t + (e − c) · (e − c) − R² = 0.
		// we may have no solution that mean no intersection or 1 or 2
		// if 2 we take the smallest value

		Vec4f RayOrigine   = ray.getOrigine();
	    Vec4f RayDirection = ray.getDirection();

		float A = Dot(RayDirection,RayDirection);
		float B = Dot((RayDirection * 2),(RayOrigine - this->Origine));
		float C = Dot((RayOrigine - this->Origine),(RayOrigine - this->Origine)) - pow(this->raduis,2);

		// let's calculate the famous Delta XD b²-4ac

		float Delta	 = pow(B,2) - (4 * A * C);
		if(Delta < 0 )
		{
			// there is no solution
			return NAN;
		}
		else
		{
			if(Delta  >= 0)
			{
				float t0 = (-B - sqrt(Delta)) / (2 * A);
				float t1 = (-B + sqrt(Delta)) / (2 * A);

				float t = MIN(t0,t1); // i don't know it's suppose to be min here but when i use min it render wrong
				if(t > 0)
				{
					return t;
				}
			}
		}

		return NAN;
	}

} /* namespace RP */
