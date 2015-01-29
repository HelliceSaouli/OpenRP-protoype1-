/*
 * RayTrace.h
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft saouli
 *
 *  this is where we do the drowing and the whole ray tracing algorithm
 *  for each pixel do
 *  	compute viewing ray
 *  	find first object hit by ray and its surface normal n
 *  	set pixel color to value computed from hit point, light, and n
 */

#ifndef RAYTRACE_H_
#define RAYTRACE_H_

#include "MHeader.h"
#include "Objects.h"
#include "vCamera.h"
#include "Color.h"
namespace RP
{

	class RayTrace
	{

		public:
			RayTrace();
			virtual ~RayTrace();
			bool Hit(const float t);
			Color* Tracer(vector<Objects*>,const vCamera&,const int w, const int h); // this is our render raytracer algorithme
	};

} /* namespace RP */

#endif /* RAYTRACE_H_ */
