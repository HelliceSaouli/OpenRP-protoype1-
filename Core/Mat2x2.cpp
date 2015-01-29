/*
 * Mat2x2.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: hakosoft
 */

#include "Mat2x2.h"

namespace RP
{

/*********************************************************************
 *
 *  defining the constractors  all 4 of them
 *
 ********************************************************************/
Mat2x2::Mat2x2()  // this will create a matrix with all zeros
{
	//Mat2x2(0); do nothing
}

Mat2x2::Mat2x2(float m00,float m01, float m10, float m11)
{
	data[0][0] =  m00; // first line row
	data[0][1] =  m01;
	data[1][0] =  m10; // 2end  line row
	data[1][1] =  m11;
}

Mat2x2::Mat2x2(float d) // this is the Identity Matrix
{
	if( d == RP_MAT2X2_IDENTITY) // if d = 1 than make
	{
		data[0][0] =  1; // first line row
		data[0][1] =  0;
		data[1][0] =  0; // 2end  line row
		data[1][1] =  1;
	}
	else
	{
		data[0][0] =  d; // first line row
		data[0][1] =  d;
		data[1][0] =  d; // 2end  line row
		data[1][1] =  d;
	}

}

Mat2x2::Mat2x2(const Vec2f &v1, const Vec2f &v2)
{
	data[0][0] =  v1[0]; // first line row
	data[0][1] =  v1[1];
	data[1][0] =  v2[0]; // 2end  line row
	data[1][1] =  v2[1];
}


Mat2x2::~Mat2x2()
{
	// TODO Auto-generated destructor stub
}


/****************************************************************
 * Overloading oprators
 ***************************************************************/

const float& Mat2x2::operator () (int i,int j)const
{

	assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
	return data[i][j];
}

float& Mat2x2::operator () (int i,int j)
{

	assert(i >= 0 ||  j >= 0); // make sure that the indices are not nigative controling x')
	return data[i][j];
}

Mat2x2 Mat2x2::operator +(const Mat2x2 &b)const
{
	Mat2x2 R;
	R(0,0) = this->data[0][0] + b(0,0);
	R(0,1) = this->data[0][1] + b(0,1);
	R(1,0) = this->data[1][0] + b(1,0);
	R(1,1) = this->data[1][1] + b(1,1);

	return R;
}

Mat2x2 Mat2x2::operator -(const Mat2x2 &b)const
{
	Mat2x2 R;
	R(0,0) = this->data[0][0] - b(0,0);
	R(0,1) = this->data[0][1] - b(0,1);
	R(1,0) = this->data[1][0] - b(1,0);
	R(1,1) = this->data[1][1] - b(1,1);

	return R;
}

Mat2x2 Mat2x2::operator *(const float s)const
{
	Mat2x2 R;
	R(0,0) = this->data[0][0] * s;
	R(0,1) = this->data[0][1] * s;
	R(1,0) = this->data[1][0] * s;
	R(1,1) = this->data[1][1] * s;

	return R;
}

Mat2x2 Mat2x2::operator *(const Mat2x2 &m) const// the matrix-matrix multiplication
{
	Mat2x2 R(0.0); // intialize a matrix with 0

	for(int i = 0; i <  2 ; i ++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			 for( int k = 0; k < 2 ; k++)
			 {
				 R(i,j) = R(i,j) + ( this->data[i][k] * m(k,j));
			 }
		}
	}

	return R;
}

Vec2f Mat2x2::operator *(const Vec2f &v)const
{
	Vec2f w(0.0);

	for(int i = 0; i <  2 ; i ++)
	{

			 for( int k = 0; k < 2 ; k++)
			 {
				 w[i] = w[i] + (this->data[i][k] * v[k]);
			 }
	}

	return w;

}

Mat2x2 Mat2x2::Transpose()
{
	// returning a matrice that have 4 value but the order is changed we are giving clouns to rows
	return Mat2x2(this->data[0][0],this->data[1][0],this->data[0][1],this->data[1][1]);
}

Mat2x2 Mat2x2::Inverse()
{
	if(this->Det()!= 0)
	{
		float X = 1 / this->Det();
		return (Mat2x2(this->data[1][1],-1 * this->data[0][1],-1 * this->data[1][0],this->data[0][0]) * X) ; // X = 1 / ad -bc the matrice is ( d,-b
	}

	return 0;
}

float Mat2x2::Det()
{
	return ( (this->data[0][0]* this->data[1][1]) - (this->data[0][1] * this->data[1][0]) );
}

} /* namespace RP */
