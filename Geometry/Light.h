/****************************************************************************
 * Light.h                                                                  *
 *                                                                          *
 *  Created on: Jan 29, 2015                                                *
 *      Author: hakosoft saouli                                             *
 *                                                                          *
 *      This is the Light classe it's so important in the rendering pipline *
 *      there are 3 major type of light :                                   *
 *      	1- A point light : the simplest. it does not have direction but *
 *      	                   it travelle for knowned distance.            *
 *      	2- A sun light   : act just like the sun all rays have the same *
 *                             direction distance does not effect           *
 *          3- A spot light  : google it lolz
 ****************************************************************************/

#ifndef LIGHT_H_
#define LIGHT_H_

#include <LightSources.h>

namespace RP
{

	// trying to be a good programmer and use some of the advenced c++ stuff

	enum LightType {POINT_LIGHT,SUN_LIGHT,SPOT_LIGHT}; // this is the 3 types of light that we will use for rendering our scens
	enum FalloffType { CONSTANTE, LINEAR };  // this will make us determen how light gonna fade when it traverse certain distense

	class Light: public LightSources
	{
		private:
		    int Lighttype;
		    int falloftype;

			float energy; 				// min = 0 that mean we are in dark no light , max  = 10
			float distance;            //  used only by the point and spot lights it is the fall of distance

			Vec4f position;			  // the position of the light source in the 3D world
			Vec4f direction;		 // the direction for directional lights , the point light does not need this

			Color lightColor;
		public:
			Light();
			Light(LightType type = POINT_LIGHT, float energy = 1,  float distance = 0,Color c = Color(1.0,1.0,1.0,1.0), Vec4f p = Vec4f(0.0,0.0,0.0,1.0), Vec4f d = Vec4f(0.0,0.0,0.0,0.0),FalloffType Ftype = CONSTANTE);
			virtual ~Light();
			/***************************************************************
			 *  some setter and getters my be i will put them us protected *
			 ***************************************************************/


			void setEnergy(float);
			void setDistance(const float);

			void setPosition(const Vec4f&);
			void setDirection(const Vec4f&);
			void setColor(const Color&);


			virtual float getEnergy()const;
			virtual float getDistance()const;

			virtual Vec4f getPosition()const;
			virtual Vec4f getDirection()const;
			virtual Color getColor()const; /// it's the light color scaled with energy

			virtual bool isPoint();
			virtual bool isDirectional();
			virtual bool isSpote();

	};

} /* namespace RP */

#endif /* LIGHT_H_ */
