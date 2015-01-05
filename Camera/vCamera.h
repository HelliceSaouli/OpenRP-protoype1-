/***************************************************************************************************
 * vCamera.h
 *
 *  Created on: Jan 2, 2015
 *      Author: hakosoft saouli
 *
 *      this is basic virual camera implimentation that will see and render  our 3D world
 *
 ***************************************************************************************************/

#ifndef VCAMERA_H_
#define VCAMERA_H_

#include "MHeader.h"
#include "Mat3x3.h"
#include "Mat4x4.h"
#include "Vec3f.h"
#include "Vec4f.h"
#include "Transforme3D.h"

namespace RP
{

	class vCamera
	{
		private:
			//Let's start with hard stuff the martices

		Mat4x4 V;												// this is view Matrix
		Mat4x4 P;												// this is projection Matrix
		Mat4x4 MVP;												// the Model-view projection Matrix MVP = V * P * M

		Vec4f CameraPos;										// the Camera positiio in the world some othere like to call it the Eye
		Vec4f Target;											// the focus point where the camera is looking Camera - targer = the vector direction
		Vec4f Direction;										// can help to set where the camera is  looking


		float NearPlane;										// the near plane of Frustrum
		float FarPlane;											// the Far plane of  Frustrum

		float Left,Right,Bottom,Top;							// the frusrum i will use it in Ortho

		float Aspectratio;
		float Fov;

		public:

			/****************************************************************
			 *                                                              *
			 *  Constractors for the Camera object                          *
			 *                                                              *
			 ****************************************************************/
			vCamera(); // Creating Camera doing nothing
			virtual ~vCamera();

			/****************************************************************
			 *                                                              *
			 *  this is bunch of methodes setter and getter and other stuff *
			 *                                                              *
			 ****************************************************************/


			/***********************Set functions***************************/
			void  setFov(float);
			void  setAspect(float);
			void  setNear(float);
			void  setFar(float);

			void  setOrthobox(Vec2f&,Vec2f&);					// this will set the ortho  box left right top and bottom

			void  setViewMatrix(Mat4x4&);						// user can set the view matrix by giving it directly one ( could be calclated some where else or readed from file
			void  setProjectionMatrix(Mat4x4&);					// set up the projection matrix by giving it one directily
			void  setModelViewProjectionMatrix(Mat4x4&);	    // set up the MVP matrix directly

			void  setPosition(Vec4f&);							// the eyes postion in the world
			void  setPosition(Vec3f&);							// the last element will be 1 if the user dont wanna use vec 4 and put every time 1 at the end of it he can put vec 3 and we do the rest for him

			void  setTarget(Vec4f&);							// this is where the camera is looking
			void  setTarget(Vec3f&);


			/***********************Get functions ***************************/
			float getFov();
			float getAspect();
			float getNear();
			float getFar();
			Vec4f getOrthobox();								// this will retrun Left righ top and buttom the near and far have there own set and get
			/*******************************************************************************
			 *
			 * so here we need to set up our  coordinate system for the Camera this
			 * done by the view matrix wich have 3 vectors u,v, and w. and vector t
			 *
			 * w: is the Z axis the Camera will look at the nigative direction w = EYE - Target
			 * u: is the X axis u =  w cross UP ; where UP is vector indicate where is up in
			 * 	  world
			 * v: is the Y axis v = w cross u
			 * t: is the origine
			 ********************************************************************************/
			Mat4x4 getViewMatrix();
			Mat4x4 getProjectionMatrix();
			Mat4x4 getModelViewProjectionMatrix();
			Vec4f  getPosition();
			Vec4f  getTarget();


			/*************************************************************/

			void calculateViewMatrix(Vec4f&);		    // in case u don't have ur Camera view matrix we can calculated here givin the postion,up,and target;
			void calculatePerpectiveMatrix();	// the prepective projection
			void calculateOrthoganalMatrix();	// the Orthoganal projection

			void calculateMVP(Mat4x4&);               // the modelvie projection that map everything from world to screen


	};

} /* namespace RP */

#endif /* VCAMERA_H_ */
