/*
 * Ray.h
 *
 *  Created on: Jan 26, 2015
 *      Author: hakosoft saouli
 *
 *      This classe is ray classe it will describe a ray with
 *      it's origine and direction.
 *      the paramitric representation of any line in 3D is
 *      p(t) = Origine + (t * Direction)
 */

#ifndef RAY_H_
#define RAY_H_

#include "MHeader.h"
#include "Vec4f.h"

namespace RP
{

	class Ray
	{
	    private:
			Vec4f origine;      // the origine of vector
			Vec4f direction;   // the direction of vector

			float step;		   // the step that the ray will march in the direction D could be used in volume redering and stuff
			/**************************************************
			 *  more stuff will be add to renforce the classe *
			 **************************************************/
		public:
			Ray(const Vec4f&, const Vec4f&); //constrator that creat a ray with giving it a position and direction easy
			virtual ~Ray();

			void setOrigine(const Vec4f&);
			void setDirection(const Vec4f&);

			Vec4f getOrigine()const;
			Vec4f getDirection()const;

	};

} /* namespace RP */

#endif /* RAY_H_ */
