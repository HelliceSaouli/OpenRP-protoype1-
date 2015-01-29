/*
 * Transforme3D.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: hakosoft
 */

#include "Transforme3D.h"

namespace RP
{

	Transforme3D::Transforme3D()
	{
		//DO NOTHING

	}

	Transforme3D::~Transforme3D()
	{
		// TODO Auto-generated destructor stub
	}

	/************************************************
	 *                                              *
	 *  1- BASIC TRANSFORMATIONS                    *
	 *                                              *
	 ************************************************/
	//1-1 the translation
	Mat4x4 Transforme3D::translate(const float tx,const float ty,const float tz)
	{
		Mat4x4 T(RP_MAT4X4_IDENTITY);

		T(0,3) = tx;
		T(1,3) = ty;
		T(2,3) = tz;
		return T;
	}

	Mat4x4 Transforme3D::translate(const Vec3f &t)
	{
		return this->translate(t[0],t[1],t[2]);
	}

	Mat4x4 Transforme3D::translate(const Vec4f &t) // lol it looks the same
	{
		//just ingore the 4th element or mybe i will devide all element by the 4 next time
		return this->translate(t[0],t[1],t[2]);
	}

	//1-2 The rotation
	Mat4x4 Transforme3D::rotation_x(const float Angle)
	{
		// converte to radien
		float Theta =  DegreeToRad(Angle);

		Vec4f row1(1.0  ,0.0       , 0.0       ,0.0);
		Vec4f row2(0.0  ,cos(Theta),-sin(Theta),0.0);
		Vec4f row3(0.0  ,sin(Theta), cos(Theta),0.0);
		Vec4f row4(0.0  ,0.0       , 0.0       ,1.0);

		Mat4x4 Rotationx(row1,row2,row3,row4);

		return Rotationx;
	}

	Mat4x4 Transforme3D::rotation_y(const float Angle)
	{
		// converte to radien
		float Theta =  DegreeToRad(Angle);

		Vec4f row1(cos(Theta)      ,0.0        , sin(Theta)       ,0.0);
		Vec4f row2(0.0  ,1.0       , 0.0       ,0.0);
		Vec4f row3(-sin(Theta)  ,0.0           , cos(Theta)      ,0.0);
		Vec4f row4(0.0  ,0.0       , 0.0       ,1.0);

		Mat4x4 Rotationy(row1,row2,row3,row4);

		return Rotationy;
	}

	Mat4x4 Transforme3D::rotation_z(const float Angle)
	{
		// converte to radien
		float Theta =  DegreeToRad(Angle);

		Vec4f row1(cos(Theta)      ,-sin(Theta),0.0       ,0.0);
		Vec4f row2(sin(Theta)      , cos(Theta),0.0       ,0.0);
		Vec4f row3(0.0  ,0.0       ,1.0        ,0.0);
		Vec4f row4(0.0  ,0.0       , 0.0       ,1.0);

		Mat4x4 Rotationz(row1,row2,row3,row4);

		return Rotationz;
	}

	//1-3 The Scale

	Mat4x4 Transforme3D::scale(const float sx,const float sy,const float sz)
	{

		Mat4x4 S(RP_MAT4X4_IDENTITY);

		S(0,0) = sx;
		S(1,1) = sy;
		S(2,2) = sz;

		return S;
	}

	Mat4x4 Transforme3D::scale(const Vec3f &s)
	{
		return this->scale(s[0],s[1],s[3]);
	}

	//1-4 rigid-body transformation

	Mat4x4 Transforme3D::Rigid(const Mat3x3 &R, const Vec3f &T)
	{

		Vec4f row1(R(0,0) ,R(0,1) , R(0,2), T[0]);
		Vec4f row2(R(1,0) ,R(1,1) , R(1,2), T[1]);
		Vec4f row3(R(2,0) ,R(2,1) , R(2,2), T[2]);
		Vec4f row4(0.0    ,0.0    , 0.0   , 1.0 );

		Mat4x4 rigid(row1,row2,row3,row4);

		return rigid;
	}

	/************************************************
	 *                                              *
	 *  2- Projective TRANSFORMATIONS               *
	 *                                              *
	 ************************************************/

	//2-1 Orthographic Projection
	Mat4x4 Transforme3D::orthographic(const float l,const float r,const float b,const float t,const float n,const float f)
	{
		Mat4x4 Ortho; // will be insilized all to 0

		Ortho(0,0) = 2 / (r-l);
		Ortho(0,3) = -((r + l) / (r - l));

		Ortho(1,1) = 2 / (t-b);
		Ortho(1,3) = -((t + b) / (t - b));

		Ortho(2,2) = 2 / (f-n);
		Ortho(2,3) = -((f + n) / (f - n));

		Ortho(3,3) = 1.0;

		return Ortho;
	}

	Mat4x4 Transforme3D::orthographic(const Vec3f& MinBox, const Vec3f& MaxBox)
	{
		float l = MinBox[0];
		float r = MaxBox[0];

		float b = MinBox[1];
		float t = MaxBox[1];

		float n = MinBox[2];
		float f = MaxBox[2];


		Mat4x4 Ortho; // will be insilized all to 0

		Ortho(0,0) = 2 / (r-l);
		Ortho(0,3) = -((r + l) / (r - l));

		Ortho(1,1) = 2 / (t-b);
		Ortho(1,3) = -((t + b) / (t - b));

		Ortho(2,2) = 2 / (f-n);
		Ortho(2,3) = -((f + n) / (f - n));

		Ortho(3,3) = 1.0;

		return Ortho;
	}

	//2-2 Perspective Projection
	/*************************************************************************************************************
	 *  this the projection matrice from openGL : https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
	 * fovy
                    Specifies the field of view angle, in degrees, in the y direction.
     * aspect
                    Specifies the aspect ratio that determines
                    the field of view in the x direction.
                    The aspect ratio is the ratio of x (width) to y (height).
     * zNear
                    Specifies the distance from the viewer to the near clipping plane
                    (always positive).
     * zFar
                    Specifies the distance from the viewer to the far clipping plane
                    (always positive).

	 **************************************************************************************************************/
	Mat4x4 Transforme3D::perspective(const float fvoy,const float aspect,const float zNear, const float zFar)
	{
		Mat4x4 Perpective; // will be insilized all to 0
		float f = cotangent(fvoy / 2);

		Perpective(0,0) = f / aspect;
		Perpective(1,1) = f;
		Perpective(2,2) = (zFar + zNear) / (zNear - zFar);
		Perpective(2,3) = 2 * ((zFar * zNear) / ( zNear - zFar));
		Perpective(3,2) = -1;

		return Perpective;
	}

	Mat4x4 Transforme3D::perspective(const Vec4f &v)
	{
		Mat4x4 Perpective; // will be insilized all to 0
		float f = cotangent(v[0]);

		Perpective(0,0) = f / v[1];
		Perpective(1,1) = f;
		Perpective(2,2) = (v[3] + v[2]) / (v[2] - v[3]);
		Perpective(2,3) = 2 * ((v[3] * v[2]) / ( v[2] - v[3]));
		Perpective(3,2) = -1;

		return Perpective;
	}

} /* namespace RP */
