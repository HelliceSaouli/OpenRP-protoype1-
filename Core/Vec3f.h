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
			Vec3f(const Vec3f& v);
			virtual ~Vec3f();

			/*****************************************************************
			 *
			 * the get and set function
			 *
			 ****************************************************************/

			float getX()const ;
			void  setX(float);
			float getY()const ;
			void  setY(float);
			float getZ()const ;
			void  setZ(float);
			void  Ones();
			void  Zeros();

			/****************************************************************
			 * Overloading oprators
			 ***************************************************************/
			const float operator [] (int i) const ;
			float& operator [] (int i); // Indexing operator so we can use  this Vec3f V ; V[i] = ? ;
			Vec3f  operator -() const; //  calculating the nigative vector if you have v(1,2) than -v(-1,-2)
			Vec3f  operator +(const Vec3f&) const ; // Add 2 vector v1 + v2
			Vec3f  operator +(const float)  const ;// Add a scalar to the vector v1 + s

			Vec3f  operator *(const Vec3f&) const ; // multi 2 vector v1 * v2
			Vec3f  operator *(const float)  const;//  multi a scalar to the vector v1 * s

			Vec3f  operator /(const float)  const;  // divde some Vector by some scalar s or  just multi it by 1/s

			Vec3f  operator -(const Vec3f&) const; // Sub 2 vector v1 - v2
			Vec3f  operator -(const float)  const;//  Sub a scalar to the vector v1 - s

			 /**************************************************************
			  * some out put function just to ease debuging                *
			  **************************************************************/
			 friend ostream& operator << (ostream& Output, const Vec3f& v)
			 {
				 return (Output << " X = " << v.x << ",Y = " << v.y <<",Z = "<<v.z<< endl);
			 }
	};


	/****************************************************************
	 *
	 * Some usefukk function
	 *
	 ****************************************************************/

	inline
	float Dot(const Vec3f &u,const Vec3f &v) // dot production
	{
		float dot = (u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ());
		return dot;
	}

	inline
	float Length(const Vec3f &v)	// calculate the lenth using sqrt and the dot product
	{
		return sqrt(Dot(v,v));
	}

	inline
	Vec3f Normalize(const Vec3f &v) 		// Elements of vector divide by the Length
	{
		Vec3f NormalizedV;

		NormalizedV.setX(v.getX() /  Length(v));
		NormalizedV.setY(v.getY() /  Length(v));
		NormalizedV.setZ(v.getZ() /  Length(v));

		return NormalizedV;
	}

	inline
	Vec3f Cross(const Vec3f &a, const Vec3f &b) // Calculate the Cross prodact of 2 vectors and with it we can  find the Angle
	{
		Vec3f CrossV;

		CrossV.setX((a.getY() *  b.getZ()) - (a.getZ() * b.getY()));
		CrossV.setY((a.getZ() *  b.getX()) - (a.getX() * b.getZ()));
		CrossV.setZ((a.getX() *  b.getY()) - (a.getY() * b.getX()));

		return CrossV;
	}

} /* namespace RP */

#endif /* Vec3f_H_ */
