/*****************************************************************
 * Vec2f.h
 *
 *  Created on: Nov 11, 2014
 *      Author: hakosoft
 *   RPVec2f :
 *   this classe discribe data structur vector 2D needed in
 *   computer graphic
 *
 *   Note : RP is stand for Reconstruction Platforme
 *****************************************************************/

#ifndef VEC2F_H_
#define VEC2F_H_

#include "MHeader.h"
namespace RP
{

	class Vec2f
	{



		private:
			float x; 	// the first component
			float y;	// the 2end  component

		public:
			/*****************************************************************
			 *
			 *  this will have a multpile constractor and one destractor
			 *
			 ****************************************************************/

			Vec2f();
			Vec2f(float);
			Vec2f(float,float);
			Vec2f(Vec2f& v);
			virtual ~Vec2f();

			/*****************************************************************
			 *
			 * the get and set function
			 *
			 * 5 days after i found that this function are so damp and usless
			 * coz i have the Indexing overload oprator Oo stupid me  i wil
			 * remove it next in  version v1.01
			 *
			 ****************************************************************/

			float getX();
			void  setX(float);
			float getY();
			void  setY(float);
			void  Ones();
			void  Zeros();

			/****************************************************************
			 * Overloading oprators
			 ***************************************************************/

			float& operator [] (int i); // Indexing operator so we can use  this Vec2f V ; V[i] = ? ;
			Vec2f  operator -() const; //  calculating the nigative vector if you have v(1,2) than -v(-1,-2)
			Vec2f  operator +(Vec2f); // Add 2 vector v1 + v2
			Vec2f  operator +(float);// Add a scalar to the vector v1 + s

			Vec2f  operator *(Vec2f); // multi 2 vector v1 * v2
			Vec2f  operator *(float);//  multi a scalar to the vector v1 * s

			Vec2f  operator /(float);  // divde some Vector by some scalar s or  just multi it by 1/s

			Vec2f  operator -(Vec2f); // Sub 2 vector v1 - v2
			Vec2f  operator -(float);//  Sub a scalar to the vector v1 - s
	};


	/****************************************************************
	 *
	 * Some usefull function
	 *
	 ****************************************************************/

	inline
	float Dot(Vec2f u,Vec2f v) // dot production
	{
		return (u.getX() * v.getX() + u.getY() * v.getY());
	}

	inline
	float Length(Vec2f v)	// calculate the lenth using sqrt and the dot product
	{
		return sqrt(Dot(v,v));
	}

	inline
	Vec2f Normalize(Vec2f v) 		// Elements of vector divide by the Length
	{
		Vec2f NormalizedV;

		NormalizedV.setX(v.getX() /  Length(v));
		NormalizedV.setY(v.getY() /  Length(v));

		return NormalizedV;
	}


} /* namespace RP */

#endif /* VEC2F_H_ */
