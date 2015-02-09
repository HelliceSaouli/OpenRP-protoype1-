/*
 * Light.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: hakosoft
 */

#include <Light.h>

namespace RP
{

	Light::Light()
	{
		//DO nothing

	}

	Light::Light(LightType type, float energy ,float distance ,Color c, Vec4f p, Vec4f d ,FalloffType Ftype)
	{
		this->Lighttype  = (int)type;
		this->energy     = energy;
		this->falloftype = (int)Ftype;
		this->distance   = distance;
		this->position   = p;
		this->direction  = d;
		this->lightColor = c;

	}
	Light::~Light()
	{
		// TODO Auto-generated destructor stub
	}

	void Light::setColor(const Color &c)
	{
		// this is the color of the light
		this->lightColor = c;
	}

	void Light::setPosition(const Vec4f &p)
	{
		// the position of the light source
		this->position = p;
	}

	void Light::setDirection(const Vec4f &d)
	{
		// this is needed only in directional light and spot light
		this->direction = d;
	}

	void Light::setDistance(const float d)
	{
		// how far light can travel
		this->distance = d;
	}

	void Light::setEnergy(float E)
	{
		//E = CLAMP(E,0.0,10.0); // majke sure that the energy betewing 0 and 10
		this->energy = E;
	}


	Color Light::getColor()const
	{
		return this->lightColor;
	}

	Vec4f Light::getPosition()const
	{
		return this->position;
	}

	Vec4f Light::getDirection()const
	{
		return this->direction;
	}

	float Light::getEnergy()const
	{
		return this->energy;
	}

	float Light::getDistance()const
	{
		return this->distance;
	}

	bool Light::isPoint()
	{
		if(this->Lighttype == (int)POINT_LIGHT)
			return true;

		return false;
	}

	bool Light::isDirectional()
	{
		if(this->Lighttype == (int)SUN_LIGHT)
			return true;

		return false;
	}

	bool Light::isSpote()
	{
		if(this->Lighttype == (int)SPOT_LIGHT)
			return true;

		return false;
	}
} /* namespace RP */
