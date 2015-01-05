/*
 * ImageBMP.h
 *
 *  Created on: Dec 28, 2014
 *      Author: hakosoft saouli
 *
 * The BMP file format, also known as bitmap image file or device independent bitmap (DIB)
 * file format or simply a bitmap, is a raster graphics image file format used to store bitmap
 * digital images, independently of the display device.
 *
 * The bitmap image file consists of fixed-size structures (headers) as well as variable-size
 * structures appearing in a predetermined sequence. Many different versions of some of these
 * structures can appear in the file, due to the long evolution of this file format.
 *
 * Bytes 0-1: Magic word. It contains the letters 'B' and 'M'.
	Bytes 2-5:   Double word. File size.
	Bytes 6-10:  Leave this zeroed .
	Bytes 11-14: Double word. Start of the bitmap.
	Bytes 15-18: Double word. Size of the header. Normally set to 40. The header is considered to start at offset 15.
	Bytes 19-22: Double word. Width.
	Bytes 23-26: Double word. Height.
	Bytes 27-28: Word. Planes. Must be 1.
	Bytes 29-30: Word. Bits per pixel. You'll need this as 24.
	Bytes 31-34: Double word. Compression. Leave it as zero.
	Bytes 35-38: Double word. Compressed size. Since there's no compression, this value will be the same as file size.
	Bytes 39-42: Double word. Horizontal resolution. See below.
	Bytes 43-46: Double word. Vertical resolution. Pixels per meter, according to Wikipedia. The values seem to vary, but 2835 should do for both.
	Bytes 47-50: Double word. Number of colors in the palette. Leave as zero.
	Bytes 51-54: Double word. "Important colors". Leave as zero.
    Bytes 55-EOF: Bitmap.

    for more information about Bitmap Images : http://en.wikipedia.org/wiki/BMP_file_format

    I chosed this format to be my class image because it's easy to implement this classe will
    be one of the out put of the rendring algorithms like Ray-tracer or OpenGL rendrere
 */

#ifndef IMAGEBMP_H_
#define IMAGEBMP_H_

#include "MHeader.h"
#include "Color.h"
#include "BITMAPINFOHEADER.h"

namespace RP
{

	class ImageBMP
	{
		private:
			 char  *filenamle;         // the path or the name of the image
		 	 unsigned int width;
		 	 unsigned int heigth;       // heigth and width of the image

		 	 unsigned int nChannel;     // supported 1-4 channels
		 	 unsigned int depth;        // the number of bits per pixel, which is the color depth of the image. Typical values are 1,4, 8, 16, 24 and 32.
		 	 unsigned int Datasize;     // the size of the data not the image with it's header this in bytes
		 	 unsigned int size;         // the size of the hole image with headrs

		 	BITMAPINFOHEADER BMPHeadr; // the info header
		 	unsigned char *PixelData; //  the image Data vector of RGBA


		public:

		 	/***********************************************************************************
		 	 * I can't see any automatic constractor to this classe my be adding it  later one *
		 	 ***********************************************************************************/
			ImageBMP();
			virtual ~ImageBMP();

			/********************************************************************
			 *  internal methodes for the classe ImageBMP like creating image   *
			 *  saving image loading it and draw it to our window....etc        *
			 *  i will ingore some stuff and some varaible here i will put in   *
			 *  considration that all my images are 32 bits (8 * 4 channal) for *
			 *  now but i will change it next version inchallah                 *
			 ********************************************************************/
			void CreateImage(unsigned int , unsigned int );          // this function will create a Image with w * h size the depth will be 32 chanel are 4
			void CreateImage(unsigned int , unsigned int, Color*);  // create from color table
			void Delete();

			bool SaveBMP(char*);    // this will save my image into bmp file
			//ImageBMP LoadBMP(); // this will load my BMP into my structure

			/************************************************************************************
			 * here will be othre function like set and get pixels deapth and number of channel *
			 * and all the stuff that helps to manuplate images                                 *
			 ************************************************************************************/

	};

	/*******************************************************
	 * some usefull functions                              *
	 *******************************************************/
	inline
	unsigned char Floattochar(float value)
	{
		return (static_cast<unsigned char>(value * 255)); // this function will give me colors in form of 8 bit number from 0 tell 255
	}

} /* namespace RP */

#endif /* IMAGEBMP_H_ */
