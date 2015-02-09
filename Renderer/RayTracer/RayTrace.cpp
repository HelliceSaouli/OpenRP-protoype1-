/*
 * RayTrace.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: hakosoft
 */

#include <RayTrace.h>

namespace RP
{

	RayTrace::RayTrace()
	{
		// DO NOTHING

	}

	RayTrace::~RayTrace()
	{
		// TODO Auto-generated destructor stub
	}

	bool RayTrace::Hit(const float t)
	{
		if(isnan(t))
			return false;
		else
			return true;

	}

	//still some work to do
	Color RayTrace::PhongShading(float IntensityEmbient,float Distance,float shiness,vector<LightSources*> source,vector<Objects *> objects,int indexObject,const Vec4f &viewdirection,Vec4f intersection)
	{
		Color  AmbiantIntesity  = objects.at(indexObject)->getKa() *  IntensityEmbient;                                        // this is the Ia * Ka where Ia is  fixed value for all rgb
		Color  DiffuseIntesity(0.0,0.0,0.0,1.0);					// this  I = Ip * Kd * (N.L)
		Color  SpecularIntesity(0.0,0.0,0.0,1.0);				// this  I = Ip * Ks * (N,H)pow(n)

		Color Colorfinal;						// the result of phong model
		//check every light source
		for(int i = 0; i < (int)source.size(); i++)
		{
			// check if  it's point light source
			if(source.at(i)->isPoint())
			{
				// 1 Calculate the intestiy of light with liner function udapted from blender
				//http://wiki.blender.org/index.php/Doc:2.6/Manual/Lighting/Lights/Light_Attenuation
				float r = Length(intersection - source.at(i)->getPosition());
				float I = source.at(i)->getEnergy() * ( Distance   / (Distance + r) ); //this is the attentation if we scal our color of light with this we get the Light intensity
				Color Ip = source.at(i)->getColor() ; //this is the Light  poinctual intensity

				//2 calculate the diffuse for ever light source
				Color KD = objects.at(indexObject)->ObjectColor() * objects.at(indexObject)->getKd(); // this the color of object multiplyed by the Kd;
				Color KS = objects.at(indexObject)->ObjectColor() * objects.at(indexObject)->getKs();

				Vec4f L  = Normalize(source.at(i)->getPosition() - intersection);
				Vec4f N  = objects.at(indexObject)->ObjectNormal_at(intersection);
				float CosTheta = Dot(N,L);

				//3-do shadows
				if(source.at(i)->getEnergy() != 0) // no shadow unless there is light we shouod change this later to  isLighton()
				{
					Ray Shadow(intersection,L); // created a shadow ray that start at the point of intersection with direction to light

					for(int i = 0; i < (int)objects.size(); i++)// check if the ray intersect with any object if yes shadow return ambient
					{
						if( i != indexObject) // so the object do not cast a shadow on his slef
						{
							float t = objects.at(i)->intersection(Shadow) + 0.0001;
							//check if there is intersection


							if(this->Hit(t))
							{
								if(t <= r) // check if distance betewen the intersection and light some times the source light could be betewen object and that will lead to wrong shadows
									return AmbiantIntesity;
							}
						}
					}
					DiffuseIntesity  = (DiffuseIntesity  + (Ip * KD * CosTheta)) * I ;

					if(objects.at(indexObject)->isShining())
					{
						Vec4f H = Normalize(L - viewdirection); // the nigative direction of view XD that mean from point to eye XD that was giving me bug but fixed
						float CosGama  = Dot(N,H);
						SpecularIntesity = (SpecularIntesity + (Ip * KS *  pow(CosGama,shiness))) * I;
					}
				}



			}
		}

		if(objects.at(indexObject)->isShining()) // check if the object is shining
			Colorfinal =  AmbiantIntesity + DiffuseIntesity + SpecularIntesity;
		else
			Colorfinal =  AmbiantIntesity + DiffuseIntesity;

		return Colorfinal;
	}

	Color* RayTrace::Tracer(vector<Objects *>scene,vector<LightSources*>sources,float Ambient,float Distance,float shiness, const vCamera &camera, const int w, const int h)
	{

		Color *pixels = new Color[w * h];
		int pixelindex = 0;
		for( int y  = 0; y < h ; y++)
		{
			for( int x = 0; x < w ; x++)
			{
				// 1- creat and cast our viewing rays we suppose that our l,r = (-1,1) and t,b = (1,-1)
				vector<float> intersections;
				vector<int> ids; // the object in the scene indexs
				float u = (x + 0.5) * 2  / w -1 ;
				float v = (y + 0.5) * 2  / h -1 ;
				float n = -1.0;//cotangent(camera.getFov()/2); // this is called the focal length

				Vec4f RayOrigine   = camera.getPosition();
				const Vec4f d = Normalize(Vec4f(u,v,n,0.0));
				Vec4f RayDirection = camera.Camera2World(d);

				Ray CastedRay(RayOrigine,RayDirection);

				//2-for each  object check the intersection
				for(int i = 0 ; i < (int)scene.size(); i++)
				{
					float t = scene.at(i)->intersection(CastedRay);
					if(this->Hit(t))
					{
						intersections.push_back(t);
						ids.push_back(scene.at(i)->getObjectID());
					}
				}

				//3-see wha we need to drow in screen
				if(intersections.size() == 0)
				{
					// there are no intersections color of background
					pixels[pixelindex] = Color::Azure * 0.5;
				}
				else
				{
					// there is intersection let's see wich one is closet to camera and drow it first
					// i feel am doing it the wrong way but Oo let's see what we will get at the end--------------> i get right XD it worked

					float min = intersections.at(0);
					int _helper = -1;

					for(int i = 0; i < (int)intersections.size(); i++)
					{
						min = MIN(min,intersections.at(i));
					}

					for(int i = 0; i < (int)intersections.size(); i++)
					{
						if( min == intersections.at(i))
							_helper = i;
					}
					//pixels[pixelindex] = scene.at(ids.at(_helper))->ObjectColor();
					//4-  use the shading model phong


						int idex = ids.at(_helper);
						Vec4f intersection = CastedRay.getOrigine() + (CastedRay.getDirection() * min ); // this the point of intresection
						pixels[pixelindex] = this->PhongShading(Ambient,Distance,shiness,sources,scene,idex,CastedRay.getDirection(),intersection);

						//pixels[pixelindex] =scene.at(idex)->ObjectColor(); // shadless
				}

				pixelindex++;
			}
			cout << " rendring ........" << (pixelindex * 100) /(w*h)<<" %" <<endl;
		}

		return pixels;
	}

} /* namespace RP */
