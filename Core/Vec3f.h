/*****************************************************************
 * Vec3f.h
 *
 *  Created on: Nov 13, 2014
 *      Author: hakosoft
 *   RPVec3f :
 *   this classe discribe data structur vector 2D needed in
 *   computer graphic
 *
 *   Note : RP is stand for Reconstruction Platforme
 *****************************************************************/

#ifndef Vec3f_H_
#define Vec3f_H_

#include "MHeader.h"
namespace RP
{

	class Vec3f
	{



		private:
			float x; 	// the first component
			float y;	// the 2end  component
			float z; 	// the 3red  component
		public:
			/*****************************************************************
			 *
			 *  this will have a multpile constractor and one destractor
			 *
			 ****************************************************************/

			Vec3f();
			Vec3f(float);
			Vec3f(float,float,float);
			Vec3f(Vec3f& v);
			virtual ~Vec3f();

			/*****************************************************************
			 *
			 * the get and set function
			 *
			 ****************************************************************/

			float getX();
			void  setX(float);
			float getY();
			void  setY(float);
			float getZ();
			void  setZ(float);
			void  Ones();
			void  Zeros();

			/****************************************************************
			 * Overloading oprators
			 ***************************************************************/

			float& operator [] (int i); // Indexing operator so we can use  this Vec3f V ; V[i] = ? ;
			Vec3f  operator -() const; //  calculating the nigative vector if you have v(1,2) than -v(-1,-2)
			Vec3f  operator +(Vec3f); // Add 2 vector v1 + v2
			Vec3f  operator +(float);// Add a scalar to the vector v1 + s

			Vec3f  operator *(Vec3f); // multi 2 vector v1 * v2
			Vec3f  operator *(float);//  multi a scalar to the vector v1 * s

			Vec3f  operator /(float);  // divde some Vector by some scalar s or  just multi it by 1/s

			Vec3f  operator -(Vec3f); // Sub 2 vector v1 - v2
			Vec3f  operator -(float);//  Sub a scalar to the vector v1 - s
	};


	/****************************************************************
	 *
	 * Some usefukk function
	 *
	 ****************************************************************/

	inline
	float Dot(Vec3f u,Vec3f v) // dot production
	{
		return (u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ());
	}

	inline
	float Length(Vec3f v)	// calculate the lenth using sqrt and the dot product
	{
		return sqrt(Dot(v,v));
	}

	inline
	Vec3f Normalize(Vec3f v) 		// Elements of vector divide by the Length
	{
		Vec3f NormalizedV;

		NormalizedV.setX(v.getX() /  Length(v));
		NormalizedV.setY(v.getY() /  Length(v));
		NormalizedV.setZ(v.getZ() /  Length(v));

		return NormalizedV;
	}

	inline
	Vec3f Cross(Vec3f a, Vec3f b) // Calculate the Cross prodact of 2 vectors and with it we can  find the Angle
	{
		Vec3f CrossV;

		CrossV.setX((a.getY() *  b.getZ()) - (a.getZ() * b.getY()));
		CrossV.setY((a.getZ() *  b.getX()) - (a.getX() * b.getZ()));
		CrossV.setZ((a.getX() *  b.getY()) - (a.getY() * b.getX()));

		return CrossV;
	}

} /* namespace RP */

#endif /* Vec3f_H_ */
