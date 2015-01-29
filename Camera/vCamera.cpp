/*
 * vCamera.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: hakosoft
 */

#include "vCamera.h"

namespace RP
{

	vCamera::vCamera()
	{
		this->CameraPos   = Vec4f(0.0,0.0,0.0,1.0);
		this->Target      = Vec4f(0.0,0.0,-1.0,1.0);

		/*this->NearPlane   = 1;
		this->FarPlane    = 1000.0;

		this->Aspectratio = 4.0/3.0;
		this->Fov         = 45.0;*/
	}

	vCamera::~vCamera()
	{
		// TODO Auto-generated destructor stub
	}

	/****************************************************************
	 *                                                              *
	 *  this is bunch of methodes setter and getter and other stuff *
	 *                                                              *
	 ****************************************************************/


	/***********************Set functions***************************/

	void vCamera::setAspect(const float aspect)
	{
		this->Aspectratio = aspect;
	}

	void vCamera::setFov(const float fovy)
	{
		this->Fov = fovy;
	}

	void vCamera::setNear(const float zNear)
	{
		this->NearPlane = zNear;
	}

	void vCamera::setFar(const float zFar)
	{
		this->FarPlane = zFar;
	}

	void vCamera::setOrthobox(const Vec2f &LeftRight,const Vec2f &BottomTop)
	{
		this->Left   = LeftRight[0];
		this->Right  = LeftRight[1];

		this->Bottom = BottomTop[0];
		this->Top    = BottomTop[1];
	}

	void vCamera::setPosition(const Vec3f &eye)
	{
		this->CameraPos[0] = eye[0];
		this->CameraPos[1] = eye[1];
		this->CameraPos[2] = eye[2];
		this->CameraPos[3] = 1.0;
	}

	void vCamera::setPosition(const Vec4f &eye)
	{
		this->CameraPos[0] = eye[0];
		this->CameraPos[1] = eye[1];
		this->CameraPos[2] = eye[2];
		this->CameraPos[3] = eye[3]; // supposed that user know what he he doing and put 1 here XD
	}

	void vCamera::setTarget(const Vec3f &at)
	{
		this->Target[0] = at[0];
		this->Target[1] = at[1];
		this->Target[2] = at[2];
		this->Target[3] = 1.0;
	}

	void vCamera::setTarget(const Vec4f &at)
	{
		this->Target[0] = at[0];
		this->Target[1] = at[1];
		this->Target[2] = at[2];
		this->Target[3] = at[3];
	}

	void vCamera::setViewMatrix(const Mat4x4 &userViewMatrix)
	{
		for(int i = 0; i< 4 ; i++)
		{
			for(int j = 0; j < 4 ; j++)
			{
					this->V(i,j) = userViewMatrix(i,j);
			}
		}
	}

	/*
	 * this matrix is  taken directly and saved in the camera
	 * mybe it was calculated some where else. we will have our
	 * function that calculate the tow projection matrices
	 * perpective or Orthogrnal projection
	 */
	void vCamera::setProjectionMatrix(const Mat4x4& userProjectionMatrix)
	{
		for(int i = 0; i< 4 ; i++)
		{
			for(int j = 0; j < 4 ; j++)
			{
					this->P(i,j) = userProjectionMatrix(i,j);
			}
		}
	}

	void vCamera::setModelViewProjectionMatrix(const Mat4x4 &userMVPMatrix)
	{
		for(int i = 0; i< 4 ; i++)
		{
			for(int j = 0; j < 4 ; j++)
			{
					this->MVP(i,j) = userMVPMatrix(i,j);
			}
		}
	}

	/***********************Get functions ***************************/

	float vCamera::getAspect()const
	{
		return this->Aspectratio;
	}

	float vCamera::getFov()const
	{
		return this->Fov;
	}

	float vCamera::getFar()const
	{
		return this->FarPlane;
	}

	float vCamera::getNear()const
	{
		return this->NearPlane;
	}

	Vec4f vCamera::getOrthobox()const
	{
		Vec4f lrbt(this->Left,this->Right,this->Bottom,this->Top);  // lrbt = left right botomm top x') lol

		return lrbt;
	}

	Vec4f vCamera::getPosition()const // remmeber this is the postion of the Camera occrding to the world cordinate
	{
		return this->CameraPos;
	}

	Vec4f vCamera::getTarget()const
	{
		return this->Target;
	}

	Mat4x4 vCamera::getViewMatrix()const
	{
		return this->V;
	}

	Mat4x4 vCamera::getModelViewProjectionMatrix()const
	{
		return this->MVP;
	}

	Mat4x4 vCamera::getProjectionMatrix()const
	{
		return this->P;
	}

	/********************** Some Calculation *********************************/

	void vCamera::calculateViewMatrix(const Vec4f &up)
	{
		//OMG takes me for ever to get it right there was so much bug

		this->Direction = this->CameraPos - this->Target;

		Vec4f w = Normalize(this->Direction);
		Vec4f u = Normalize(Cross(up,w));
		Vec4f v = Normalize(Cross(w,u));
		Vec4f t = Vec4f(0.0,0.0,0.0,1.0);

		Transforme3D Translate;
		this->V = Mat4x4(u,v,w,t).Transpose() * Translate.translate(-this->CameraPos);

	}

	void vCamera::calculatePerpectiveMatrix()
	{
		Transforme3D  perspective;
		Mat4x4 m = perspective.perspective(this->Fov,this->Aspectratio,this->NearPlane,this->FarPlane);
		this->P = m;
	}

	void vCamera::calculateOrthoganalMatrix()
	{
		Transforme3D Ortho;
		Mat4x4 m = Ortho.orthographic(this->Left,this->Right,this->Bottom,this->Top,this->NearPlane,this->FarPlane);
		this->P = m;
	}

	void vCamera::calculateMVP(const Mat4x4 &ModelMatrix)
	{
		this->MVP = this->P * this ->V * ModelMatrix; // where ModelMatrix is the all the translation rotation scals that happend to the model
	}

	Vec4f vCamera::World2Camra(const Vec4f &p)const
	{
		Vec4f w2c = this->V * p;
		return w2c;
	}

	Vec4f vCamera::Camera2World(const Vec4f &p)const
	{
		Mat4x4 invers = this->V;
		Vec4f c2w = invers.Inverse() * p;
		return c2w;
	}
} /* namespace RP */
