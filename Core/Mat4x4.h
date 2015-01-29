/*
 * Mat4x4.h
 *
 *  Created on: Dec 23, 2014
 *      Author: hakosoft
 */

#ifndef MAT4X4_H_
#define MAT4X4_H_

#ifndef RP_MAT4X4_IDENTITY
#define RP_MAT4X4_IDENTITY 1
#endif

#include "MHeader.h"
#include "Vec4f.h"
#include "Vec3f.h"
#include "Mat3x3.h"

namespace RP
{

	class Mat4x4
	{
			private:
				float data[4][4]; // a 4 by 4 array to store the data in
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

				Mat4x4();
				Mat4x4(float ,float ,float,float, float,float,float,float, float,float,float,float, float,float,float,float);
				Mat4x4(const Vec4f&,const Vec4f&,const Vec4f&,const Vec4f&);
			  //Mat4x4(Vec2f,Vec2f,Vec2f,Vec2f,Vec2f,Vec2f,Vec2f,Vec2f);
				Mat4x4(float d); // if d = 1 create the identity matrix else create a matrix with the float d
				virtual ~Mat4x4();


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
				const float& operator () (int i,int j)const;
				Mat4x4 operator + (const Mat4x4&)const; // this componentwise addition, very similar to vector-vector addition.
				Mat4x4 operator - (const Mat4x4&)const; // this componentwise Subbtraction very similar to vector-vector Subbtraction.
				Mat4x4 operator * (const Mat4x4&)const; // this NOT componentwise multiplication it's the standard multiplication of matrices
				Mat4x4 operator * (const float)const; // multiplaying the whool matrix  with a floating scalar
				Vec4f  operator * (const Vec4f&)const; // Matrice x Vector usfull in tansformation a lot


				 friend ostream& operator << (ostream& Output, const Mat4x4& v)
				 {
					 return (Output <<"M[0][0] = "<< v(0,0) << " M[0][1] = " << v(0,1) <<" M[0][2] = " << v(0,2) <<" M[0][3] = " << v(0,3) << endl
							        <<"M[1][0] = "<< v(1,0) << " M[1][1] = " << v(1,1) <<" M[1][2] = " << v(1,2) <<" M[1][3] = " << v(1,3) << endl
							        <<"M[2][0] = "<< v(2,0) << " M[2][1] = " << v(2,1) <<" M[2][2] = " << v(2,2) <<" M[2][3] = " << v(2,3) << endl
							        <<"M[3][0] = "<< v(3,0) << " M[3][1] = " << v(3,1) <<" M[3][2] = " << v(3,2) <<" M[3][3] = " << v(3,3) << endl);
				 }

				/****************************************************************
				 *
				 * Some usefull function
				 *
				 ****************************************************************/
				Mat4x4 Transpose(); // this is the transpose of Matrice where rows will be colones and so the coulons will be rows
				Mat4x4 Inverse(); // calculate it later on
				Mat4x4 Adjoints(); // usful for calclating Inverse and other stuff
				float Det(); // Determinant of a Matrix only calculated if we have a squar Matrices M(a,b ; c,d) Det(m) = ad - bc
				int UpperTraingler();/*this function will return -1 or 1 why ? well becoz if there is a swap in lane
									 * the determan will  change the singe i need to know that
									 */
		};

		/****************************************************************
		 *
		 * Some usefull function
		 *
		 ****************************************************************/
	inline
	float Tr(const Mat4x4 &M) // The trace of a matrix, denoted tr(M), is simply the sum of the diagonal elements of a square matrix,
	{
		float trace = 0;
		trace = M(0,0) + M(1,1) + M(2,2) + M(3,3); // the demantion is 4x4 we dont need  the Computer to do the fun stuff for us X")
		return trace;
	}

	inline
	Mat4x4 MatrixcomponentwiseMul(const Mat4x4 &a,const Mat4x4 &b) // this is the componentwise multiplication
	{
		Mat4x4 c;

		c(0,0) = a(0,0) * b(0,0);
		c(0,1) = a(0,1) * b(0,1);
		c(0,2) = a(0,2) * b(0,2);
		c(0,3) = a(0,3) * b(0,3);

		c(1,0) = a(1,0) * b(1,0);
		c(1,1) = a(1,1) * b(1,1);
		c(1,2) = a(1,2) * b(1,2);
		c(1,3) = a(1,3) * b(1,3);

		c(2,0) = a(2,0) * b(2,0);
		c(2,1) = a(2,1) * b(2,1);
		c(2,2) = a(2,2) * b(2,2);
		c(2,3) = a(2,3) * b(2,3);

		c(3,0) = a(3,0) * b(3,0);
		c(3,1) = a(3,1) * b(3,1);
		c(3,2) = a(3,2) * b(3,2);
		c(3,3) = a(3,3) * b(3,3);

		return c;
	}

	inline
	float Cofactor(int Row, int Col,Mat4x4 A)  //math.tutorvista.com/algebra/cofactor-matrix.html
	{
		assert(Row >= 0 ||  Col >= 0);
		int indx = 0;
		float SubMat[9];

		// programming with stupid way probebly there is better way to do it x')
		for (int i = 0 ; i < 4 ; i++)
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				if(i !=  Row && j != Col)
				{
					 SubMat[indx]= A(i,j);
					 indx++;
				}

			}
		}

		// puting our sub matrix 3x3 togther
		Vec3f Line1(SubMat[0],SubMat[1],SubMat[2]);
		Vec3f Line2(SubMat[3],SubMat[4],SubMat[5]);
		Vec3f Line3(SubMat[6],SubMat[7],SubMat[8]);
		Mat3x3 SubMatrix(Line1,Line2,Line3);

		// calculate the the |SubMatrix|

		return SubMatrix.Det();
	}

} /* namespace RP */

#endif /* MAT4X4_H_ */
