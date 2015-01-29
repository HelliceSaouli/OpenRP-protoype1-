/*
 * Mat3x3.h
 *
 *  Created on: Dec 22, 2014
 *      Author: hakosoft
 *      this will handle the Matrix data 3x3
 */

#ifndef MAT3X3_H_
#define MAT3X3_H_

#ifndef RP_MAT3X3_IDENTITY
#define RP_MAT3X3_IDENTITY 1
#endif
#include "MHeader.h"
#include "Vec3f.h"
#include "Vec2f.h"
#include "Mat2x2.h"

namespace RP
{

	class Mat3x3
	{
			private:
				float data[3][3]; // a 3 by 3 array to store the data in
			//	int col; // indicator for colons
			//	int row; // indicator for rows

			public:

				/********************************************************
				 *
				 * Create 4 constructors
				 * - one uses 4 floats to feel up the matrix
				 * - one uses 2 Vec3f each one of it represent a row
				 * - one build an Identity Matrix
				 * - one just Empty matrix full of zeros
				 *
				 *******************************************************/

				Mat3x3();
				Mat3x3(float ,float ,float ,float,float,float,float,float,float);
				Mat3x3(const Vec3f&, const Vec3f&,const Vec3f&);
				Mat3x3(float d); // if d = 1 create the identity matrix else create a matrix with the float d
				virtual ~Mat3x3();


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

				float& operator () (int i,int j); // Nice simple way to index wi use to have Matrix M[0][0] now we can just use M(0,0)
				const float&  operator () (int i,int j)const;
				Mat3x3 operator + (const Mat3x3&)const; // this componentwise addition, very similar to vector-vector addition.
				Mat3x3 operator - (const Mat3x3&)const; // this componentwise Subbtraction very similar to vector-vector Subbtraction.
				Mat3x3 operator * (const Mat3x3&)const; // this NOT componentwise multiplication it's the standard multiplication of matrices
				Mat3x3 operator * (const float)const; // multiplaying the whool matrix  with a floating scalar
				Vec3f  operator * (const Vec3f&)const;

				/****************************************************************
				 *
				 * Some usefull function
				 *
				 ****************************************************************/

				 friend ostream& operator << (ostream& Output, const Mat3x3& v)
				 {
					 return (Output <<"M[0][0] = "<< v(0,0) << " M[0][1] = " << v(0,1) <<" M[0][2] = " << v(0,2) << endl
							        <<"M[1][0] = "<< v(1,0) << " M[1][1] = " << v(1,1) <<" M[1][2] = " << v(1,2) << endl
							        <<"M[2][0] = "<< v(2,0) << " M[2][1] = " << v(2,1) <<" M[2][2] = " << v(2,2) << endl);
				 }
				Mat3x3 Transpose(); // this is the transpose of Matrice where rows will be colones and so the coulons will be rows
				Mat3x3 Inverse(); // calculate it later on
				Mat3x3 Adjoints(); // usful for calclating Inverse and other stuff
				float Det(); // Determinant of a Matrix only calculated if we have a squar Matrices M(a,b ; c,d) Det(m) = ad - bc

		};

		/****************************************************************
		 *
		 * Some usefull function
		 *
		 ****************************************************************/
	inline
	float Tr(const Mat3x3 &M) // The trace of a matrix, denoted tr(M), is simply the sum of the diagonal elements of a square matrix,
	{
		float trace = 0;
		trace = M(0,0) + M(1,1) + M(2,2); // the demantion is 3x3 we dont need  the Computer to do the fun stuff for us X")
		return trace;
	}

	inline
	Mat3x3 MatrixcomponentwiseMul(const Mat3x3 &a,const Mat3x3 &b) // this is the componentwise multiplication
	{
		Mat3x3 c;

		c(0,0) = a(0,0) * b(0,0);
		c(0,1) = a(0,1) * b(0,1);
		c(0,2) = a(0,2) * b(0,2);

		c(1,0) = a(1,0) * b(1,0);
		c(1,1) = a(1,1) * b(1,1);
		c(1,2) = a(1,2) * b(1,2);

		c(2,0) = a(2,0) * b(2,0);
		c(2,1) = a(2,1) * b(2,1);
		c(2,2) = a(2,2) * b(2,2);

		return c;
	}

	inline
	float Cofactor(int Row, int Col,Mat3x3 A)  // http://www.mathwords.com/a/adjoint.htm
	{
		assert(Row >= 0 ||  Col >= 0);
		int indx = 0;
		float SubMat[4];

		// programming with stupid way probebly there is better way to do it x')
		for (int i = 0 ; i < 3 ; i++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				if(i !=  Row && j != Col)
				{
					 SubMat[indx]= A(i,j);
					 indx++;
				}

			}
		}

		// puting our sub matrix 2x2 togther
		Vec2f Line1(SubMat[0],SubMat[1]);
		Vec2f Line2(SubMat[2],SubMat[3]);
		Mat2x2 SubMatrix(Line1,Line2);

		// calculate the the |SubMatrix|

		return SubMatrix.Det();
	}
} /* namespace RP */

#endif /* MAT3X3_H_ */
