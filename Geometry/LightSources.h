/*************************************************************************************
 * LightSources.h                                                                    *
 *                                                                                   *
 *  Created on: Jan 29, 2015                                                         *
 *      Author: hakosoft saouli                                                      *
 *      this classe will be the holdetr for all the lights in the scene. every render*
 *      algorithm implimented will take it as an argument                            *
 *************************************************************************************/

#ifndef LIGHTSOURCES_H_
#define LIGHTSOURCES_H_

#include "MHeader.h"
#include "Color.h"
#include "Vec4f.h"
namespace RP
{

	// fo know it has nothing
	class LightSources
	{
		public:
			LightSources();
			virtual ~LightSources();

			virtual float getEnergy()const;
			virtual float getDistance()const;

			virtual Vec4f getPosition()const;
			virtual Vec4f getDirection()const;
			virtual Color getColor()const;

			virtual bool isPoint();
			virtual bool isDirectional();
			virtual bool isSpote();
	};

} /* namespace RP */

#endif /* LIGHTSOURCES_H_ */
