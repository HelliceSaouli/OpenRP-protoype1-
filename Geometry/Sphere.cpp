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
	}

	Sphere::Sphere(const Vec4f &o, float r, const Color &c)
	{
		this->Origine = o;
		this->raduis  = r;
		this->color   = c;
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
			if(Delta  == 0)
			{
				//there is one solution -b/2a
				float t = - B / (2* A);
				if(t > 0)
				  return t;
				else
					return NAN;
			}
			else
			{
				// there is 2 solution return the min

				float a = (-B + sqrt(Delta)) / (2 * A);
				float b = (-B - sqrt(Delta)) / (2 * A);

				float t = MAX(a,b);

				if(t > 0)
				  return t;
				else
					return NAN; //intersection bihind the camera
				return t;
			}
		}
	}

} /* namespace RP */
