/*
 * Ray.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: hakosoft
 */

#include <Ray.h>

namespace RP
{

	Ray::Ray(const Vec4f &o, const Vec4f &d)
	{
		this->origine   = o;
		this->direction = d;
		this->step = 0.0; // for now it's 0.0
	}

	Ray::~Ray()
	{
		// TODO Auto-generated destructor stub
	}


	/********************************************************
	 * Setter and getter                                    *
	 ********************************************************/

	void Ray::setDirection(const Vec4f &d)
	{
		this->direction = d;
	}

	Vec4f Ray::getDirection()const
	{
		return this->direction;
	}

	void Ray::setOrigine(const Vec4f &o)
	{
		this->direction = o;
	}

	Vec4f Ray::getOrigine()const
	{
		return this->origine;
	}

} /* namespace RP */
