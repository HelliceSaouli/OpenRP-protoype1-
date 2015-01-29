/*****************************************************
 * Mat2x2.h

 *
 *  Created on: Nov 15, 2014
 *      Author: hakosoft
 *      this will handle the matrix Data
 *****************************************************/

#ifndef MAT2X2_H_
#define MAT2X2_H_

#ifndef RP_MAT2X2_IDENTITY
#define RP_MAT2X2_IDENTITY 1
#endif

#include "MHeader.h"
#include "Vec2f.h"
namespace RP
{

	class Mat2x2
	{
		private:
			float data[2][2]; // a 2 by 2 array to store the data in
		//	int col; // indicator for colons
		//	int row; // indicator for rows

		public:

			/********************************************************
			 *
			 * Create 4 constructors
			 * - one uses 4 floats to feel up the matrix
			 * - one uses 2 Vec2f each one of it represent a row
			 * - one build an Identity Matrix
			 * - one just Empty matrix full of zeros
			 *
			 *******************************************************/

			Mat2x2();
			Mat2x2(float ,float ,float ,float);
			Mat2x2(const Vec2f&,const Vec2f&);
			Mat2x2(float d); // if d = 1 create the identity matrix else create a matrix with the float d
			virtual ~Mat2x2();


			/*****************************************************************
			 *
			 * the get and set function we overload one function and we call
			 * it at(), where :
			 * -set function is ----> at(i,j,float);
			 * -get function is ----> float at(i,j);
			 *
			 ****************************************************************/

			/*void  at(int,int,float);
			float at(int,int);*/

			/****************************************************************
			 * Overloading oprators
			 ***************************************************************/
			float& operator () (int i,int j); //this is for normal use and to avoid the Lvalue error omg hard c++ the othere is for where there is const arrguments
		    const float& operator () (int i,int j)const; // Nice simple way to index wi use to have Matrix M[0][0] now we can just use M(0,0)
			Mat2x2 operator + (const Mat2x2&)const; // this componentwise addition, very similar to vector-vector addition.
			Mat2x2 operator - (const Mat2x2&)const; // this componentwise Subbtraction very similar to vector-vector Subbtraction.
			Mat2x2 operator * (const Mat2x2&)const; // this NOT componentwise multiplication it's the standard multiplication of matrices
			Mat2x2 operator * (const float)const; // multiplaying the whool matrix  with a floating scalar
			Vec2f  operator * (const Vec2f&)const ;

			/****************************************************************
			 *
			 * Some usefull function
			 *
			 ****************************************************************/
			Mat2x2 Transpose(); // this is the transpose of Matrice where rows will be colones and so the coulons will be rows
			Mat2x2 Inverse(); // calculate it later on
			float Det(); // Determinant of a Matrix only calculated if we have a squar Matrices M(a,b ; c,d) Det(m) = ad - bc

			 friend ostream& operator << (ostream& Output, const Mat2x2& v)
			 {
				 return (Output <<"M[0][0] = "<< v(0,0) << " M[0][1] = " << v(0,1) << endl
						        <<"M[1][0] = "<< v(1,0) << " M[1][1] = " << v(1,1) << endl);
			 }

	};

	/****************************************************************
	 *
	 * Some usefull function
	 *
	 ****************************************************************/
inline
float Tr(const Mat2x2 &M) // The trace of a matrix, denoted tr(M), is simply the sum of the diagonal elements of a square matrix,
{
	float trace = 0;
	trace = M(0,0) + M(1,1); // the demantion is 2x2 we dont need  the Computer to do the fun stuff for us X")
	return trace;
}

inline
Mat2x2 MatrixcomponentwiseMul(const Mat2x2 &a,const Mat2x2 &b) // this is the componentwise multiplication
{
	Mat2x2 c;

	c(0,0) = a(0,0) * b(0,0);
	c(0,1) = a(0,1) * b(0,1);
	c(1,0) = a(1,0) * b(1,0);
	c(1,1) = a(1,1) * b(1,1);

	return c;
}
} /* namespace RP */

#endif /* MAT2X2_H_ */
