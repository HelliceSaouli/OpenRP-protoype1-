/*
 * LightSources.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: hakosoft
 */

#include <LightSources.h>

namespace RP
{

	LightSources::LightSources()
	{
		// TODO Auto-generated constructor stub

	}

	LightSources::~LightSources()
	{
		// TODO Auto-generated destructor stub
	}


	Color LightSources::getColor()const
	{
		return Color::white;
	}

	Vec4f LightSources::getPosition()const
	{
		return Vec4f(0.0,0.0,0.0,1.0);
	}

	Vec4f LightSources::getDirection()const
	{
		return Vec4f(0.0,0.0,0.0,0.0);
	}

	float LightSources::getEnergy()const
	{
		return 1.0;
	}

	float LightSources::getDistance()const
	{
		return 0.0;
	}

	bool LightSources::isPoint()
	{
		return false;
	}

	bool LightSources::isDirectional()
	{

		return false;
	}

	bool LightSources::isSpote()
	{
		return false;
	}
} /* namespace RP */
