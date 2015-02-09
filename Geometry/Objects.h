/*
 * Objects.h
 *
 *  Created on: Jan 26, 2015
 *      Author: hakosoft saouli
 *
 *      This classe will hold our object in the scene
 *      for testing sake will use only sphere and planes
 *      next we will replace this classe with a true classe
 *      call it Mesh wich contain all description about objects in
 *      out scene
 *
 *      Object is the mother classe of plane and sphere
 */

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "MHeader.h"
#include "Color.h"
#include "Ray.h"

namespace RP
{

class Objects
{

	private:
		int objectID;
	public:
		Objects();
		virtual ~Objects();
		virtual float intersection(const Ray&);
		virtual Color ObjectColor();
		virtual Vec4f ObjectNormal_at(const Vec4f&)const;
		// this will be changeed since we are going to add matriel clkasse later on
		virtual Color getKa()const;
		virtual Color getKs()const;
		virtual Color getKd()const;

		virtual bool isShining();
		void setObjectID(int);
		int  getObjectID();
	};

} /* namespace RP */

#endif /* OBJECTS_H_ */
