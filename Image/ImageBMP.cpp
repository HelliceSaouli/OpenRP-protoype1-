/*
 * ImageBMP.cpp
 *
 *  Created on: Dec 28, 2014
 *      Author: hakosoft
 */

#include "ImageBMP.h"

namespace RP
{

	ImageBMP::ImageBMP()
	{
		// DO NOTHING
	}

	ImageBMP::~ImageBMP()
	{
	}

	/*******************************************************************************
	 *  the 2 function that create my Image giving to it only the width and height *
	 *  and or the color data wich is converted to char (1 byte)                   *
	 *******************************************************************************/
	void ImageBMP::CreateImage(unsigned int w, unsigned int h)
	{
		this->width  = w;
		this->heigth = h;

		this->nChannel = 4; // RGBA we are assuming that  every one had
		this->depth    = 32;// 8 bits * 4 channels

		this->Datasize = this->width * this->heigth *  this->nChannel; // this will give the size in bytes(octees)
		this->PixelData = new unsigned char[this->Datasize];

		//this will create an image with white color

		for(int i = 0; i < (int)this->Datasize; i++)
		{
			this->PixelData[i] = static_cast<unsigned char>(255);
		}

	}

	void ImageBMP::CreateImage(unsigned int w, unsigned int h,Color *colors)
	{
		this->width  = w;
		this->heigth = h;

		this->nChannel = 4; // RGBA we are assuming that  every one had
		this->depth    = 32;// 8 bits * 4 channels

		this->Datasize = this->width * this->heigth *  this->nChannel; // this will give the size in bytes(octees)
		this->PixelData = new unsigned char[this->Datasize];

		for(int i = 0; i < (int)(w*h); i++)
		{
			//Vec4f color = colors[i].get(); it doesnt work like that i should ovrload the = operator i guess
			Vec4f color;
			color = colors[i].get(); // it works like that Oo wierd
			this->PixelData[(i* 4)+ 0] = Floattochar(color[0]); // red
			this->PixelData[(i* 4)+ 1] = Floattochar(color[1]); // green
			this->PixelData[(i* 4)+ 2] = Floattochar(color[2]); // blue
			this->PixelData[(i* 4)+ 3] = Floattochar(color[3]); // Alpha
		}
	}

	void ImageBMP::Delete()
	{
		delete[] this->PixelData;
	}

	bool ImageBMP::SaveBMP(char *Name)
	{
		/******************************************
		 * First of all let's start buy feeling up*
		 * the header file of the BMP             *
		 *                                        *
		 ******************************************/

		this->BMPHeadr.MagicNumber[0] = 'B';
		this->BMPHeadr.MagicNumber[1] = 'M';

		this->size                    = this->Datasize + 54;
		this->BMPHeadr.Size 		  = this->size;
		this->BMPHeadr.Unused1        = 0;
		this->BMPHeadr.unused2        = 0;
		this->BMPHeadr.Offset         = 54;

		this->BMPHeadr.DIBsize        = 40;
		this->BMPHeadr.Width          = this->width;
		this->BMPHeadr.Heigth         = this->heigth;
		this->BMPHeadr.Planes         = 1;
		this->BMPHeadr.Depth          = this->depth;
		this->BMPHeadr.Compression    = 0;
		this->BMPHeadr.ImageSize      = this->Datasize;
		this->BMPHeadr.XPelsPerMeter  = 2835;
		this->BMPHeadr.YPelsPerMeter  = 2835;
		this->BMPHeadr.ColorImportant = 0;
		this->BMPHeadr.ColorUsed      = 0;


		/*********************************************
		 * after we created the header let's open up *
		 * a file and put all in it                  *
		 *********************************************/

		ofstream Image(Name,ios::out|ios::binary); // crteate file to hole the information on my file

		if(Image.is_open())
		{

			Image.write((char*)&this->BMPHeadr,54);
			Image.write((char*)this->PixelData,this->Datasize);
			Image.close();

		}
		else
		{
			cerr<< " bug"<< endl;
			return false;

		}

		return true;
	}


} /* namespace RP */
