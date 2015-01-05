/***********************************************************************************
 * Transforme3D.h
 *
 *  Created on: Dec 31, 2014
 *      Author: hakosoft saouli
 *
 *	A transform is an operation that takes entities such as points, vectors, or
 *	colors and converts them in some way. For the computer graphics practitioner,
 *	it is extremely important to master transforms. With them, you can position,
 *	reshape, and animate objects, lights, and cameras.
 *
 *	You can also ensure that all computations are carried out in the same coordinate
 *	system, and project objects onto a plane in different ways.
 *  for more infomartion check out : Real-time rendring 3rd edition book.
 *
 *  this classe is build to present almost all the transformations frome translating
 *  up to Eluer rotations and  3D  to 2D projection.
 *
 *  this classe will had no variables,it will have only methodes to calculate stuff,
 *  it can be also the daughter of other classes like Mesh,Camera,Color,Light..etc,
 *  i will not be doing this for this version of platfrome but i will take it in
 *  in considration next version nchallah
 *************************************************************************************/

#ifndef TRANSFORME3D_H_
#define TRANSFORME3D_H_

#include "MHeader.h"

/****************************************
 * the matrices and vectores are needed *
 ****************************************/
#include "Mat3x3.h"
#include "Mat4x4.h"
#include "Vec3f.h"
#include "Vec4f.h"

namespace RP
{

	class Transforme3D
	{
		public:
			Transforme3D();
			virtual ~Transforme3D();

			/************************************************
			 *                                              *
			 *  1- BASIC TRANSFORMATIONS                    *
			 *                                              *
			 ************************************************/

			//1-1 the translation : A change from one location to another is represented by a translation matrix, T.

			Mat4x4 translate(float,float,float); // give it the position we wanna translate too as suprate  numbers
			Mat4x4 translate(Vec4f&); 	        //  give it the position as vector 4 (augmeted vector (x,y,z,1) if your last element was not a 1 the function will ignorte any way
			Mat4x4 translate(Vec3f&);			//  give it the postion simply as vector 3

			//1-2 The rotation : A rotation transform rotates a vector (position or direction) by a given angle around a given axis passing through the origin.
			Mat4x4 rotation_x(float);          // rotation around the x axis with angle O in radian
			Mat4x4 rotation_y(float);          // rotation around the y axis with angle O in radian
			Mat4x4 rotation_z(float);          // rotation around the z axis with angle O in radian

			//1-3 The Scale : scales an entity with factors sx, sy,and sz along the x-, y-, and z- directions respectively.
			Mat4x4 scale(float,float,float);
			Mat4x4 scale(Vec3f&);

			//1-4 rigid-body transformation : this transformation is the fusion of 2 in one matrix ( translation than rotation)
			Mat4x4 Rigid(Mat3x3&,Vec3f&); 		// we will give it the  3x3 rotation matrix R and the vector 3 T of translation

			//1-5 Affine transformation : need to have a 3x4 matrice i dont have right now so next time i will add it
			/************************************************
			 *                                              *
			 *  2- Projective TRANSFORMATIONS               *
			 *                                              *
			 ************************************************/

			//2-1 Orthographic Projection A characteristic of an orthographic projection is that parallel lines remain parallel after the projection.
			Mat4x4 orthographic(float,float,float ,float,float,float); // (l, r, b, t, n, f), denoting the left, right, bottom, top, near, and far planes
			Mat4x4 orthographic(Vec3f&,Vec3f&); 					   // AABB (Axis-Aligned Bounding Box) where the first vector 3 is (l,b,n) and the scend is (r,t,f)

			//2-2 Perspective Projection : which is used in the majority of computer graphics applications. Here, parallel lines are generally not parallel after projection;
			//rather, they may converge to a single point at their extreme.

			Mat4x4 perspective(float,float,float,float); // this  4 element are the angle,the aspect ratio, the near and the far
			Mat4x4 perspective(Vec4f&);					// the same top parametre but htey are giving in form of vector 4

			/******************************************************************
			 *                                                                *
			 *  3- Complex TRANSFORMATIONS                                    *
			 *  this transformation are most of them rotations like Eluer and *
			 *  other so i will add them next time                            *                                            *
			 ******************************************************************/
	};

} /* namespace RP */

#endif /* TRANSFORME3D_H_ */
