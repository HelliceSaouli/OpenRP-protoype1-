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

	bool RayTrace::Hit(float t)
	{
		if(isnan(t))
			return false;
		else
			return true;

	}

	Color* RayTrace::Tracer(vector<Objects *>scene, const vCamera &camera, const int w, const int h)
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
						cout << " t = "<< t << endl;
						intersections.push_back(t);
						ids.push_back(scene.at(i)->getObjectID());
					}
				}

				//3-see wha we need to drow in screen
				if(intersections.size() == 0)
				{
					// there are no intersections color of background
					pixels[pixelindex] = Color::black;
					cout << " No intersection"<<endl;
				}
				else
				{
					cout << "intersection "<< intersections.size()<<endl;
					// there is intersection let's see wich one is closet to camera and drow it first
					// i feel am doing it the wrong way nut Oo let's see what we will get at the end

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
					cout <<" Helper = "<< _helper<< " ids size " << ids.size()<< "object id " <<ids.at(_helper)<<endl;
					pixels[pixelindex] = scene.at(ids.at(_helper))->ObjectColor();

				}

				cout << " Rendring pixel ["<<x<<"]["<<y<<"] the color is"<<endl<<pixels[pixelindex]<<endl;
				pixelindex++;
			}
		}

		return pixels;
	}

} /* namespace RP */
