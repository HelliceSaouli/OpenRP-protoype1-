/*
 * BITMAPINFOHEADER.h
 *
 *  Created on: Dec 29, 2014
 *      Author: hakosoft saouli
 *
 *     this structur will hold all the information in the bitmap header
 *     This block of bytes is at the start of the file and is used to identify
 *     the file. A typical application reads this block first to ensure that the
 *     file is actually a BMP file and that it is not damaged.
 *
 *     for more info check : http://en.wikipedia.org/wiki/BMP_file_format
 *     						 http://msdn.microsoft.com/en-us/library/cc953fe1.aspx
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_


struct  BITMAPINFOHEADER
{

	//BMP HEADER
	unsigned char MagicNumber[2];                          //Magic number (unsigned integer 66, 77 or the 'B' and 'M')
	unsigned int  Size;                                   // Size of the BMP file in bytes
	short         Unused1;
	short         unused2;                               //Application specific
	unsigned int  Offset;								//Offset where the pixel array (bitmap data) can be found

	/**********************************************************
	 * Device-independent bitmaps or DIB header :             *
	 * This block of bytes tells the application detailed     *
	 * information about the image, which will be used to     *
	 * display the image on the screen.                       *
	 *                                                        *
	 * he reason that there are different headers is that     *
	 * Microsoft extended the DIB format several times.       *
	 * The new extended headers can be used with some GDI     *
	 * functions instead of the older ones, providing more    *
	 * functionality.                                         *
	 * For compatibility reasons we will use the old DIB      *
	 * format that have 40 bytes                              *
	 **********************************************************/
	unsigned int DIBsize; 						 // Number of bytes in the DIB header (from this point)
	unsigned int Width;
	unsigned int Heigth;                         // heigth and width of the image
	short        Planes;						 // Number of color planes being used ( most of the time 1 )
	short        Depth;							 // Number of bits per pixel
	unsigned int Compression;					 // some flag if Compression ever used probebly i will not use it so i wilet it 0
	unsigned int ImageSize;                      // Size of the raw bitmap data (including padding) -- Data size
	unsigned int XPelsPerMeter;
	unsigned int YPelsPerMeter;					 // Print resolution of the image, example 72 DPI × 39.3701 inches per meter yields 2834.6472
	unsigned int ColorUsed;                     //  Number of colors in the palette
	unsigned int ColorImportant;               //   0 means all colors are important
} __attribute__ ((packed));

// thx to this site : http://stackoverflow.com/questions/24436515/programatically-making-an-bmp-image i was able to solve the problem
//where when my image created i can't open it the prob was the ppadding tht BMP file expected
#endif /* BITMAPINFOHEADER_H_ */
