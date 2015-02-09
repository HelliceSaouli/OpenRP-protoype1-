/*
 * Plane.h
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft
 *
 *      this classe will represent a plane with it's implicite representation
 *      plane  = N.(p-p0) = 0 that mean if a point p is on the plane than
 *      the line betewen this point and origine is prependicular to the normal
 *      of the plane.
 *
 *      this classe is a  dother of object classe and it's only for testing
 *      it will be removed in the othere version.
 */

#ifndef PLANE_H_
#define PLANE_H_

#include <Objects.h>
#include "Vec4f.h"

namespace RP
{

	class Plane: public Objects
	{

		private:
			Vec4f position;
			Vec4f normal; // every point of the plane has the plane normal for now
			Color color;
			//some matrials next time it will be a full structur
			Color Ka,Kd,Ks;

		public:
			Plane();
			Plane(const Vec4f&, const Vec4f&,const Color&);
			virtual ~Plane();
			virtual float intersection(const Ray&);
			virtual Color ObjectColor();

			void setPosition(const Vec4f&);
			void setNormal(const Vec4f&);

			virtual Color getKa()const;
			virtual Color getKs()const;
			virtual Color getKd()const;


			void  setKs(const Color);
			void  setKa(const Color);
			void  setKd(const Color);


			Vec4f getPosition()const;
			Vec4f getNormal()const;
			virtual Vec4f ObjectNormal_at(const Vec4f&)const;
			virtual bool isShining();
	};

} /* namespace RP */

#endif /* PLANE_H_ */
