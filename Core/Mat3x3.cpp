/*
 * Mat3x3.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: hakosoft
 */

#include "Mat3x3.h"

namespace RP
{

	/*********************************************************************
	 *
	 *  defining the constractors  all 4 of them
	 *
	 ********************************************************************/
	Mat3x3::Mat3x3()  // this will create a matrix with all zeros
	{
		Mat3x3(0);
	}

	Mat3x3::Mat3x3(float m00,float m01,float m02, float m10, float m11,float m12, float m20, float m21,float m22)
	{
		data[0][0] =  m00; // first line row
		data[0][1] =  m01;
		data[0][2] =  m02;

		data[1][0] =  m10; // 2end  line row
		data[1][1] =  m11;
		data[1][2] =  m12;

		data[2][0] =  m20; // 3rd  line row
		data[2][1] =  m21;
		data[2][2] =  m22;


	}

	Mat3x3::Mat3x3(float d) // this is the Identity Matrix
	{
		if( d == RP_MAT3X3_IDENTITY) // if d = 1 than make
		{
			data[0][0] =  1; // first line row
			data[0][1] =  0;
			data[0][2] =  0;

			data[1][0] =  0; // 2end  line row
			data[1][1] =  1;
			data[1][2] =  0;

			data[2][0] =  0; // 3rd  line row
			data[2][1] =  0;
			data[2][2] =  1;
		}
		else
		{
			data[0][0] =  d; // first line row
			data[0][1] =  d;
			data[0][2] =  d;

			data[1][0] =  d; // 2end  line row
			data[1][1] =  d;
			data[1][2] =  d;

			data[2][0] =  d; // 3rd  line row
			data[2][1] =  d;
			data[2][2] =  d;
		}

	}

	Mat3x3::Mat3x3(const Vec3f &v1,const Vec3f &v2,const Vec3f &v3)
	{
		data[0][0] =  v1[0]; // first line row
		data[0][1] =  v1[1];
		data[0][2] =  v1[2];

		data[1][0] =  v2[0]; // 2end  line row
		data[1][1] =  v2[1];
		data[1][2] =  v2[2];

		data[2][0] =  v3[0]; // 3rd  line row
		data[2][1] =  v3[1];
		data[2][2] =  v3[2];

	}


	Mat3x3::~Mat3x3()
	{
		// TODO Auto-generated destructor stub
	}


	/****************************************************************
	 * Overloading oprators
	 ***************************************************************/

	float& Mat3x3::operator () (int i,int j)
	{

		assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
		return data[i][j];
	}

	const float& Mat3x3::operator () (int i,int j)const
	{

		assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
		return data[i][j];
	}

	Mat3x3 Mat3x3::operator +(const Mat3x3 &b)const
	{
		Mat3x3 R;
		R(0,0) = this->data[0][0] + b(0,0);
		R(0,1) = this->data[0][1] + b(0,1);
		R(0,2) = this->data[0][2] + b(0,2);

		R(1,0) = this->data[1][0] + b(1,0);
		R(1,1) = this->data[1][1] + b(1,1);
		R(1,2) = this->data[1][2] + b(1,2);

		R(2,0) = this->data[2][0] + b(2,0);
		R(2,1) = this->data[2][1] + b(2,1);
		R(2,2) = this->data[2][2] + b(2,2);

		return R;
	}

	Mat3x3 Mat3x3::operator -(const Mat3x3 &b)const
	{
		Mat3x3 R;
		R(0,0) = this->data[0][0] - b(0,0);
		R(0,1) = this->data[0][1] - b(0,1);
		R(0,2) = this->data[0][2] - b(0,2);

		R(1,0) = this->data[1][0] - b(1,0);
		R(1,1) = this->data[1][1] - b(1,1);
		R(1,2) = this->data[1][2] - b(1,2);

		R(2,0) = this->data[2][0] - b(2,0);
		R(2,1) = this->data[2][1] - b(2,1);
		R(2,2) = this->data[2][2] - b(2,2);

		return R;
	}

	Mat3x3 Mat3x3::operator *(const float s)const
	{
		Mat3x3 R;
		R(0,0) = this->data[0][0] * s;
		R(0,1) = this->data[0][1] * s;
		R(0,2) = this->data[0][2] * s;

		R(1,0) = this->data[1][0] * s;
		R(1,1) = this->data[1][1] * s;
		R(1,2) = this->data[1][2] * s;

		R(2,0) = this->data[2][0] * s;
		R(2,1) = this->data[2][1] * s;
		R(2,2) = this->data[2][2] * s;

		return R;
	}

	Mat3x3 Mat3x3::operator *(const Mat3x3 &m)const // the matrix-matrix multiplication
	{
		Mat3x3 R(0.0); // intialize a matrix with 0

		for(int i = 0; i <  3 ; i ++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				 for( int k = 0; k < 3 ; k++)
				 {
					 R(i,j) = R(i,j) + ( this->data[i][k] * m(k,j));
				 }
			}
		}

		return R;
	}

	Vec3f Mat3x3::operator *(const Vec3f &v)const
	{
		Vec3f w(0.0);

		for(int i = 0; i <  3 ; i ++)
		{

				 for( int k = 0; k < 3 ; k++)
				 {
					 w[i] = w[i] + (this->data[i][k] * v[k]);
				 }
		}

		return w;

	}

	Mat3x3 Mat3x3::Transpose()
	{
		// returning a matrice that have 9 value but the order is changed we are giving clouns to rows
		return Mat3x3(this->data[0][0],this->data[1][0],this->data[2][0],
				      this->data[0][1],this->data[1][1],this->data[2][1],
				      this->data[0][2],this->data[1][2],this->data[2][2]);
	}

	float Mat3x3::Det()
	{
		return ( (this->data[0][0] * this->data[1][1] * this->data[2][2]) +
				 (this->data[0][1] * this->data[1][2] * this->data[2][0]) +
				 (this->data[0][2] * this->data[1][0] * this->data[2][1]) -
				 (this->data[0][2] * this->data[1][1] * this->data[2][0]) -
				 (this->data[0][1] * this->data[1][0] * this->data[2][2]) -
				 (this->data[0][0] * this->data[1][2] * this->data[2][1]));
	}

	Mat3x3 Mat3x3::Adjoints() // using the cofactor we can calculate the Adjoint and after we can use it to calculate invers
	{
		Mat3x3 Adj;

		for (int i  = 0; i < 3 ; i++)
		{
			for(int j = 0; j < 3 ; j++)
			{
				Adj(i,j) = pow(-1, i+j) * Cofactor(i,j,*this);
			}
		}


		return Adj.Transpose(); // tested and it works just fine :)
	}

	/* this inverse of 3  x 3 matrix the methode used here is explict methode read it from
	 * real time rendring page 902, where u have to calculate the Adjoint wich is a matrix
	 * of sub matrices dertminent than we have to flip it after that we mulit with 1 / |m|
	 * and here we have our inversed Matrix kind of hard math LoL but it's fun.xb
	 */
	Mat3x3 Mat3x3::Inverse()
	{
		if(this->Det()!= 0)
		{
			 float X = 1/ this->Det();
			 Mat3x3 Inver = this->Adjoints() *  X;

			 return Inver;
		}

		 // return matrix of zeros if there is no  inverse == determinant = 0
		return 0;
	}

} /* namespace RP */ /* namespace RP */
