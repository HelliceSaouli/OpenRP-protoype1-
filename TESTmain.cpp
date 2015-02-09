/*
 * TESTmain.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: hakosoft
 *      this is for testing
 */

#include "Core/MHeader.h"
#include "Core/Mat4x4.h"
#include "Core/Vec4f.h"
#include "Camera/vCamera.h"
#include "Image/ImageBMP.h"
#include "Geometry/Plane.h"
#include "Geometry/Sphere.h"
#include "Geometry/Objects.h"
#include "Geometry/LightSources.h"
#include "Geometry/Light.h"
#include "Renderer/RayTracer/RayTrace.h"

using namespace RP; // i look so pro XDD


int main()
{

	//let's Create my Camera
	vCamera Cam;
	Vec4f CamUp(0.0,1.0,0.0,0.0);
	Vec4f CamPosition(0.0,0.0,2.0,1.0);
	Vec4f CamTarget(0.0,0.0,0.0,1.0);
	//float Fov = 50.0;
	Cam.setPosition(CamPosition);
	Cam.setTarget(CamTarget);
	//Cam.setFov(Fov);
	Cam.calculateViewMatrix(CamUp);

	// objects of the scene

	Vec4f PlanePosition(0.0,-0.5,0.0,1.0);
	Vec4f PlaneNormal(0.0,1.0,0.0,0.0); // bug here check it out later
	Color PlaneColor = Color::darkgreen;
	Plane plane1(PlanePosition,PlaneNormal,PlaneColor);
	plane1.setKa(Color(0.2,0.2,0.2,1));
	plane1.setKd(Color(0.8,0.8,0.9,1));

	Vec4f SpherePosition(0.0,0.0,0.0,1.0);
	float SphereRaduis = 0.5;
	Color SphereColor  = Color::gold;
	Sphere sphere1(SpherePosition, SphereRaduis, SphereColor);
	sphere1.setKa(Color(0.24725 ,0.1995 ,0.0745 ,1));
	sphere1.setKd(Color(0.75164 ,0.60648 ,0.22648 ,1));
	sphere1.setKs(Color(0.628281,0.555802 ,0.366065,1));


	// store objects in to one array so we can check them one buy one
	vector<Objects*>Scene;
	Scene.push_back(dynamic_cast <Objects*>(&plane1));
	Scene[0]->setObjectID(0);
	Scene.push_back(dynamic_cast <Objects*>(&sphere1));
	Scene[1]->setObjectID(1);



	// Create our light sources one poinctual source
	Vec4f LightPoisition(-2.0,2.0,3.0,1.0);
	float Energy     = 3;
	float Distance   = 5.0;
	Color WhiteLight = Color::white; // only white light works Oo somthing is worng check it later-----------> fixed it was the energy * I that was wrong
	float AmbientLightEnerg = 0.08;
	float shiness = 52.1;
	Light light0(POINT_LIGHT,Energy,Distance,WhiteLight,LightPoisition);

	vector<LightSources*> Sources;
	Sources.push_back(dynamic_cast<LightSources*>(&light0));

	// create the image
	RayTrace render;
	Color *pixels;

    pixels = render.Tracer(Scene,Sources,AmbientLightEnerg,Distance,shiness,Cam,640,480);

    ImageBMP img;
    img.CreateImage(640,480,pixels);
    img.SaveBMP("Image.bmp");
}
