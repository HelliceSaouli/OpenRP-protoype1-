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

		this->NearPlane   = 0.1;
		this->FarPlane    = 100.0;

		this->Aspectratio = 4.0/3.0;
		this->Fov         = 45.0;
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

	void vCamera::setAspect(float aspect)
	{
		this->Aspectratio = aspect;
	}

	void vCamera::setFov(float fovy)
	{
		this->Fov = fovy;
	}

	void vCamera::setNear(float zNear)
	{
		this->NearPlane = zNear;
	}

	void vCamera::setFar(float zFar)
	{
		this->FarPlane = zFar;
	}

	void vCamera::setOrthobox(Vec2f &LeftRight, Vec2f &BottomTop)
	{
		this->Left   = LeftRight[0];
		this->Right  = LeftRight[1];

		this->Bottom = BottomTop[0];
		this->Top    = BottomTop[1];
	}

	void vCamera::setPosition(Vec3f &eye)
	{
		this->CameraPos[0] = eye[0];
		this->CameraPos[1] = eye[1];
		this->CameraPos[2] = eye[2];
		this->CameraPos[3] = 1.0;
	}

	void vCamera::setPosition(Vec4f &eye)
	{
		this->CameraPos[0] = eye[0];
		this->CameraPos[1] = eye[1];
		this->CameraPos[2] = eye[2];
		this->CameraPos[3] = eye[3];
	}

	void vCamera::setTarget(Vec3f &at)
	{
		this->Target[0] = at[0];
		this->Target[1] = at[1];
		this->Target[2] = at[2];
		this->Target[3] = 1.0;
	}

	void vCamera::setTarget(Vec4f &at)
	{
		this->Target[0] = at[0];
		this->Target[1] = at[1];
		this->Target[2] = at[2];
		this->Target[3] = at[3];
	}

	void vCamera::setViewMatrix(Mat4x4 &userViewMatrix)
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
	void vCamera::setProjectionMatrix(Mat4x4& userProjectionMatrix)
	{
		for(int i = 0; i< 4 ; i++)
		{
			for(int j = 0; j < 4 ; j++)
			{
					this->P(i,j) = userProjectionMatrix(i,j);
			}
		}
	}

	void vCamera::setModelViewProjectionMatrix(Mat4x4 &userMVPMatrix)
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

	float vCamera::getAspect()
	{
		return this->Aspectratio;
	}

	float vCamera::getFov()
	{
		return this->Fov;
	}

	float vCamera::getFar()
	{
		return this->FarPlane;
	}

	float vCamera::getNear()
	{
		return this->NearPlane;
	}

	Vec4f vCamera::getOrthobox()
	{
		Vec4f lrbt(this->Left,this->Right,this->Bottom,this->Top);  // lrbt = left right botomm top x') lol

		return lrbt;
	}

	Vec4f vCamera::getPosition() // remmeber this is the postion of the Camera occrding to the world cordinate
	{
		return this->CameraPos;
	}

	Vec4f vCamera::getTarget()
	{
		return this->Target;
	}

	Mat4x4 vCamera::getViewMatrix()
	{
		return this->V;
	}

	Mat4x4 vCamera::getModelViewProjectionMatrix()
	{
		return this->MVP;
	}

	Mat4x4 vCamera::getProjectionMatrix()
	{
		return this->P;
	}

	/********************** Some Calculation *********************************/

	void vCamera::calculateViewMatrix(Vec4f &up)
	{
		//OMG takes me for ever to get it right there was so much bug

		this->Direction = this->CameraPos - this->Target;
		Vec4f cross;

		Vec4f w;
		w = Normalize(this->Direction);

		Vec4f u;
		cross =  Cross(up,w);
		u = Normalize(cross);

		Vec4f v;
		cross = Cross(w,u);
		v = Normalize(cross);

		Vec4f t;
		t = Vec4f(0.0,0.0,0.0,1.0);

		Transforme3D Translate;
		this->CameraPos = -this->CameraPos;
		this->V = Mat4x4(u,v,w,t).Transpose() * Translate.translate(this->CameraPos);

	}

	void vCamera::calculatePerpectiveMatrix()
	{
		Transforme3D  perspective;
		Mat4x4 m;

		m = perspective.perspective(this->Fov,this->Aspectratio,this->NearPlane,this->FarPlane);
		this->P = m;
	}

	void vCamera::calculateOrthoganalMatrix()
	{
		Transforme3D Ortho;
		Mat4x4 m;

		m = Ortho.orthographic(this->Left,this->Right,this->Bottom,this->Top,this->NearPlane,this->FarPlane);
		this->P = m;
	}

	void vCamera::calculateMVP(Mat4x4 &ModelMatrix)
	{
		this->MVP = this->P * this ->V * ModelMatrix; // where ModelMatrix is the all the translation rotation scals that happend to the model
	}
} /* namespace RP */
