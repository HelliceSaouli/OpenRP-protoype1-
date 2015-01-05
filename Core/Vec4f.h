/*****************************************************************
 * Vec4f.h
 *
 *  Created on: Nov 15, 2014
 *      Author: hakosoft
 *   RPVec4f :
 *   this classe discribe data structur vector 2D needed in
 *   computer graphic
 *
 *   Note : RP is stand for Reconstruction Platforme
 *****************************************************************/

#ifndef Vec4f_H_
#define Vec4f_H_

#include "MHeader.h"
namespace RP
{

	class Vec4f
	{



		private:
			float x; 	// the first component
			float y;	// the 2end  component
			float z; 	// the 3red  component
			float w;	// the 4th   component

		public:
			/*****************************************************************
			 *
			 *  this will have a multpile constractor and one destractor
			 *
			 ****************************************************************/

			Vec4f();
			Vec4f(float);
			Vec4f(float,float,float,float);
			Vec4f(Vec4f& v);
			virtual ~Vec4f();

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
			float getW();
			void  setW(float);
			void  Ones();
			void  Zeros();

			/****************************************************************
			 * Overloading oprators
			 ***************************************************************/

			float& operator [] (int i); // Indexing operator so we can use  this Vec4f V ; V[i] = ? ;
			Vec4f  operator -() const; //  calculating the nigative vector if you have v(1,2) than -v(-1,-2)
			Vec4f  operator +(Vec4f); // Add 2 vector v1 + v2
			Vec4f  operator +(float);// Add a scalar to the vector v1 + s

			Vec4f  operator *(Vec4f); // multi 2 vector v1 * v2
			Vec4f  operator *(float);//  multi a scalar to the vector v1 * s

			Vec4f  operator /(float);  // divde some Vector by some scalar s or  just multi it by 1/s

			Vec4f  operator -(Vec4f); // Sub 2 vector v1 - v2
			Vec4f  operator -(float);//  Sub a scalar to the vector v1 - s
	};


	/****************************************************************
	 *
	 * Some usefukk function
	 *
	 ****************************************************************/

	inline
	float Dot(Vec4f u,Vec4f v) // dot production
	{
		return (u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ() + u.getW() * v.getW());
	}

	inline
	float Length(Vec4f v)	// calculate the lenth using sqrt and the dot product
	{
		return sqrt(Dot(v,v));
	}

	inline
	Vec4f Normalize(Vec4f v) 		// Elements of vector divide by the Length
	{
		Vec4f NormalizedV;

		NormalizedV.setX(v.getX() /  Length(v));
		NormalizedV.setY(v.getY() /  Length(v));
		NormalizedV.setZ(v.getZ() /  Length(v));
		NormalizedV.setW(v.getW() /  Length(v));

		return NormalizedV;
	}

	inline
	Vec4f Cross(Vec4f a, Vec4f b) // Calculate the Cross prodact of 2 vectors and with it we can  find the Angle
	{
		Vec4f CrossV;

		CrossV.setX((a.getY() *  b.getZ()) - (a.getZ() * b.getY()));
		CrossV.setY((a.getZ() *  b.getX()) - (a.getX() * b.getZ()));
		CrossV.setZ((a.getX() *  b.getY()) - (a.getY() * b.getX()));
		CrossV.setW(0.0);

		return CrossV;
	}

} /* namespace RP */

#endif /* Vec4f_H_ */
