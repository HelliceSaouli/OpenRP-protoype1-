/*
 * Objects.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: hakosoft
 */

#include <Objects.h>

namespace RP
{

	Objects::Objects()
	{
		// TODO Auto-generated constructor stub

	}

	Objects::~Objects()
	{
		// TODO Auto-generated destructor stub
	}

	float Objects::intersection(const Ray &ray)
	{
		return 0;
	}

	Color Objects::ObjectColor()
	{
		return Color::black;
	}

	Vec4f Objects::ObjectNormal_at(const Vec4f&)const
	{
		return Vec4f(0.0,1.0,0.0,0.0);
	}

	void Objects::setObjectID(int ID)
	{
		this->objectID = ID;
	}

	int Objects::getObjectID()
	{
		return this->objectID;
	}

   Color Objects::getKa()const
   {
	   return Color::black;
   }

   Color Objects::getKs()const
   {
	   return Color::black;
   }

   Color Objects::getKd()const
   {
	   return Color::black;
   }

   bool Objects::isShining()
   {
	   return false;
   }

} /* namespace RP */
