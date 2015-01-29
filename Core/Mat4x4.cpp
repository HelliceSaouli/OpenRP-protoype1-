/*
 * Mat4x4.cpp
 *
 *  Created on: Dec 23, 2014
 *      Author: hakosoft
 */

#include "Mat4x4.h"

namespace RP
{

/*********************************************************************
	 *
	 *  defining the constractors  all 4 of them
	 *
	 ********************************************************************/
	Mat4x4::Mat4x4()  // this will create a matrix with all zeros
	{
		Mat4x4(0);
	}

	Mat4x4::Mat4x4(float m00,float m01,float m02,float m03,
			       float m10,float m11,float m12,float m13,
			       float m20,float m21,float m22,float m23,
			       float m30,float m31,float m32,float m33)
	{
		data[0][0] =  m00; // first line row
		data[0][1] =  m01;
		data[0][2] =  m02;
		data[0][3] =  m03;

		data[1][0] =  m10; // 2end  line row
		data[1][1] =  m11;
		data[1][2] =  m12;
		data[1][3] =  m13;

		data[2][0] =  m20; // 3rd  line row
		data[2][1] =  m21;
		data[2][2] =  m22;
		data[2][3] =  m23;

		data[3][0] =  m30; // 4th line row
		data[3][1] =  m31;
		data[3][2] =  m32;
		data[3][3] =  m33;

	}

	Mat4x4::Mat4x4(float d) // this is the Identity Matrix
	{
		if( d == RP_MAT4X4_IDENTITY) // if d = 1 than make
		{
			data[0][0] =  1; // first line row
			data[0][1] =  0;
			data[0][2] =  0;
			data[0][3] =  0;

			data[1][0] =  0; // 2end  line row
			data[1][1] =  1;
			data[1][2] =  0;
			data[1][3] =  0;

			data[2][0] =  0; // 3rd  line row
			data[2][1] =  0;
			data[2][2] =  1;
			data[2][3] =  0;

			data[3][0] =  0; // 4th  line row
			data[3][1] =  0;
			data[3][2] =  0;
			data[3][3] =  1;
		}
		else
		{
			data[0][0] =  d; // first line row
			data[0][1] =  d;
			data[0][2] =  d;
			data[0][3] =  d;

			data[1][0] =  d; // 2end  line row
			data[1][1] =  d;
			data[1][2] =  d;
			data[1][3] =  d;

			data[2][0] =  d; // 3rd  line row
			data[2][1] =  d;
			data[2][2] =  d;
			data[2][3] =  d;

			data[3][0] =  d; // 4th  line row
			data[3][1] =  d;
			data[3][2] =  d;
			data[3][3] =  d;
		}

	}

	Mat4x4::Mat4x4(const Vec4f &v1,const  Vec4f &v2,const Vec4f &v3,const Vec4f &v4)
	{
		data[0][0] =  v1[0]; // first line row
		data[0][1] =  v1[1];
		data[0][2] =  v1[2];
		data[0][3] =  v1[2];

		data[1][0] =  v2[0]; // 2end  line row
		data[1][1] =  v2[1];
		data[1][2] =  v2[2];
		data[1][3] =  v2[3];

		data[2][0] =  v3[0]; // 3rd  line row
		data[2][1] =  v3[1];
		data[2][2] =  v3[2];
		data[2][3] =  v3[3];

		data[3][0] =  v4[0]; // 3rd  line row
		data[3][1] =  v4[1];
		data[3][2] =  v4[2];
		data[3][3] =  v4[3];

	}


	Mat4x4::~Mat4x4()
	{
		// TODO Auto-generated destructor stub
	}


	/****************************************************************
	 * Overloading oprators
	 ***************************************************************/

	float& Mat4x4::operator () (int i,int j)
	{

		assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
		//make sure to check also if i and j are less than 4
		return data[i][j];
	}

	const float& Mat4x4::operator () (int i,int j)const
	{

		assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
		//make sure to check also if i and j are less than 4
		return data[i][j];
	}

	Mat4x4 Mat4x4::operator +(const Mat4x4 &b)const
	{
		Mat4x4 R;
		R(0,0) = this->data[0][0] + b(0,0);
		R(0,1) = this->data[0][1] + b(0,1);
		R(0,2) = this->data[0][2] + b(0,2);
		R(0,3) = this->data[0][3] + b(0,3);

		R(1,0) = this->data[1][0] + b(1,0);
		R(1,1) = this->data[1][1] + b(1,1);
		R(1,2) = this->data[1][2] + b(1,2);
		R(1,3) = this->data[1][3] + b(1,3);

		R(2,0) = this->data[2][0] + b(2,0);
		R(2,1) = this->data[2][1] + b(2,1);
		R(2,2) = this->data[2][2] + b(2,2);
		R(2,3) = this->data[2][3] + b(2,3);

		R(3,0) = this->data[3][0] + b(3,0);
		R(3,1) = this->data[3][1] + b(3,1);
		R(3,2) = this->data[3][2] + b(3,2);
		R(3,3) = this->data[3][3] + b(3,3);

		return R;
	}

	Mat4x4 Mat4x4::operator -(const Mat4x4 &b)const
	{
		Mat4x4 R;
		R(0,0) = this->data[0][0] - b(0,0);
		R(0,1) = this->data[0][1] - b(0,1);
		R(0,2) = this->data[0][2] - b(0,2);
		R(0,3) = this->data[0][3] - b(0,3);

		R(1,0) = this->data[1][0] - b(1,0);
		R(1,1) = this->data[1][1] - b(1,1);
		R(1,2) = this->data[1][2] - b(1,2);
		R(1,3) = this->data[1][3] - b(1,3);

		R(2,0) = this->data[2][0] - b(2,0);
		R(2,1) = this->data[2][1] - b(2,1);
		R(2,2) = this->data[2][2] - b(2,2);
		R(2,3) = this->data[2][3] - b(2,3);

		R(3,0) = this->data[3][0] - b(3,0);
		R(3,1) = this->data[3][1] - b(3,1);
		R(3,2) = this->data[3][2] - b(3,2);
		R(3,3) = this->data[3][3] - b(3,3);

		return R;
	}

	Mat4x4 Mat4x4::operator *(const float s)const
	{
		Mat4x4 R;
		R(0,0) = this->data[0][0] * s;
		R(0,1) = this->data[0][1] * s;
		R(0,2) = this->data[0][2] * s;
		R(0,3) = this->data[0][3] * s;

		R(1,0) = this->data[1][0] * s;
		R(1,1) = this->data[1][1] * s;
		R(1,2) = this->data[1][2] * s;
		R(1,3) = this->data[1][3] * s;

		R(2,0) = this->data[2][0] * s;
		R(2,1) = this->data[2][1] * s;
		R(2,2) = this->data[2][2] * s;
		R(2,3) = this->data[2][3] * s;

		R(3,0) = this->data[3][0] * s;
		R(3,1) = this->data[3][1] * s;
		R(3,2) = this->data[3][2] * s;
		R(3,3) = this->data[3][3] * s;

		return R;
	}

	Mat4x4 Mat4x4::operator *(const Mat4x4 &m)const // the matrix-matrix multiplication
	{
		Mat4x4 R(0.0); // intialize a matrix with 0

		for(int i = 0; i <  4 ; i ++)
		{
			for(int j = 0 ; j < 4 ; j++)
			{
				 for( int k = 0; k < 4 ; k++)
				 {
					 R(i,j) = R(i,j) + ( this->data[i][k] * m(k,j));
				 }
			}
		}

		return R;
	}

	Vec4f Mat4x4::operator *(const Vec4f &v)const
	{
		Vec4f w(0.0);

		for(int i = 0; i <  4 ; i ++)
		{

				 for( int k = 0; k < 4 ; k++)
				 {
					 w[i] = w[i] + (this->data[i][k] * v[k]);
				 }
		}

		return w;

	}
/***********************************************************************************************************/
/**********************************************************************************************************/

	Mat4x4 Mat4x4::Transpose()
	{
		// returning a matrice that have 9 value but the order is changed we are giving clouns to rows
		return Mat4x4(this->data[0][0],this->data[1][0],this->data[2][0],this->data[3][0],
				      this->data[0][1],this->data[1][1],this->data[2][1],this->data[3][1],
				      this->data[0][2],this->data[1][2],this->data[2][2],this->data[3][2],
				      this->data[0][3],this->data[1][3],this->data[2][3],this->data[3][3]);
	}

	/* we convert a matrix to an other Matrix that the half down of it are 0
	 * and the other upper half is non 0 we can use it to calculate the determinant
	 * i found the Algorithme when i was teatching Matlb that was cool
	 * it will probably gona coz trouble spicialy when we have some 0 elements
	 * in the matrix or fi el9otre
	 */
	int Mat4x4::UpperTraingler()
	{
		int swap = 1; // the detector of swaping lane
		for(int k = 0; k < 3; k++)
		{
			for(int i = k + 1; i < 4 ; i++)
			{
				// we have to check if  we dont have a 0 division if we do we should swap the two lines
				if(this->data[k][k] == 0)
				{
					float exchange; // will help me to swap the 2 lines
					for(int kk = 0; kk < 4 ; kk++)
					{
						exchange = this->data[k][kk];
						this->data[k][kk] = this->data[k+1][kk];
						this->data[k+1][kk] = exchange;
					}
					//we have lane swap so the determna shoud change it's singe
					swap = swap * -1;

				}
				float L = this->data[i][k] / this->data[k][k];

				for(int j = k; j < 4; j++)
				{
					this->data[i][j] = this->data[i][j] - (L * this->data[k][j]);
				}
			}
		}

		// on case somthing goes wrong put down the no  number value to zeros example
		// when we try to have the triangler matrix of A (1...16) there wil be a line full of
		//zeroes that mean no metter what you do no there will be alwz division by zero so we put the wrong value to zero and rest in peace XD

		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(isnan(this->data[i][j]))
					this->data[i][j] = 0.0;
			}
		}

		return swap;
	}

	float Mat4x4::Det() // the determan here is  =  to the multipliquation of el9otre of the uppertrainglir matrix if there is swap the determan shoud change it's singe
	{
		int Swap = this->UpperTraingler();
		return (Swap * (this->data[0][0]*this->data[1][1]*this->data[2][2]*this->data[3][3]));
	}

	Mat4x4 Mat4x4::Adjoints() // using the cofactor we can calculate the Adjoint and after we can use it to calculate invers
	{
		Mat4x4 Adj;

		for (int i  = 0; i < 4 ; i++)
		{
			for(int j = 0; j < 4 ; j++)
			{
				Adj(i,j) = pow(-1, i+j) * Cofactor(i,j,*this);
			}
		}


		return Adj.Transpose(); // tested and it works just fine :)
	}

	/* this inverse of 4  x 4 matrix the methode used here is explict methode read it from
	 * real time rendring page 902, where u have to calculate the Adjoint wich is a matrix
	 * of sub matrices dertminent than we have to flip it after that we mulit with 1 / |m|
	 * and here we have our inversed Matrix kind of hard math LoL but it's fun.xb
	 */
	Mat4x4 Mat4x4::Inverse()
	{
		 Mat4x4 Inver = this->Adjoints();
		 float determanent = this->Det(); // calling this function wee earase the original matrix i should change this soon x')

		 if(determanent != 0)
		  {
				 float X = 1/determanent;
				 Inver = Inver * X;

				 return Inver;
		  }
		 // return matrix of zeros if there is no  inverse == determinant = 0
		 return 0;
	}

} /* namespace RP */
