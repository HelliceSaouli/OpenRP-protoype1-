/*
 * Sphere.h
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft saouli
 *
 *      This classe will represent a sphere with it's implicte forme
 *      (x-x0)² + (y-y0)² + (z-z0)² = 0
 *      all we need to do give is a center and the raduis of the sphere
 *      and we ready to go
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <Objects.h>
#include "Vec4f.h"

namespace RP
{

	class Sphere: public Objects
	{
		private:
			Vec4f Origine;
			float raduis;
			Color color;

		public:
			Sphere();
			Sphere(const Vec4f&,float ,const Color&);
			virtual ~Sphere();
			virtual float intersection(const Ray&);
			virtual Color ObjectColor();

			void  setOrigine(const Vec4f&);
			Vec4f getOrigine()const;
			float getRaduis()const;
	};

} /* namespace RP */

#endif /* SPHERE_H_ */
