/*
 * Color.h
 *
 *  Created on: Dec 25, 2014
 *      Author: hakosoft saouli
 *      This  Classe represent a color using RGBA model, therefore it stores 3 numbers
 *      representing The R (Red), The B (blue), The G (Green) and one other number to
 *      be the Alpha value that define the transperncy.
 *      Each of the R, G, B and A components is represented by a float number in  the
 *      range of [0-1] higher precision representations of a given color and are used
 *      in special cases where precision color math is required.
 *
 *      where 0 is no color and one is full color
 *      Note  uchar Pixel =  Color * 255
 *
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "Vec3f.h"
#include "Vec4f.h"
namespace RP
{

	class Color
	{
	    private:
			float r; // Red color
			float g; // Green color
			float b; // blue color
			float a; // the Alpha color

		public:

			/********************************************************************************
			 * Static colors name so that the user can set the color he want to use by it's *
			 * name . I'am not putting all the colors right know but i will add them later  *
			 * example : Color Value = Color:: white                                        *
			 ********************************************************************************/

			// white colors
			static const Color white,Azure,whitesmook;

			// Gray Colors
			static const Color gray,silver,slategray,black;

			//Red Colors
			static const Color red,crimson,darkred;

			//Pink Colors
			static const Color pink,lightpink,hotpink;

			// Orange Colors
			static const Color orange,colar,orangered;

			//Yellow colors
			static const Color yellow,gold;

			//Brown colors
			static const Color brown,maroon;

			//Green Colors
			static const Color green,lime,darkgreen;

			//Blue Colors
			static const Color blue,aqua,darkblue;

			//Purple Colors
			static const Color purple,magenta,indgo;

			/*****************************************************************
			 *                                                               *
			 *  this will have a multpile constractor and one destractor     *
			 *                                                               *
			 *****************************************************************/

			Color();
			Color(float,float,float,float); // for deferent floats range beteween 0-1
			Color(const Vec4f&); // we can create a color by passing to it a vector 4 of floats
			Color(const Vec3f&,float); // we can create a color by passing to it a vector 3 of floats and alpha value
			Color(const Color&); //create a color with othere color
			virtual ~Color();

			/*****************************************************************
			 *                                                               *
		     * the get and set function                                      *
		     *****************************************************************/

			void  set(float,float,float,float); // use this to set the color after all the RGB are privats and we need setter and getter
			Vec4f get()const; // get the color and save it in vector of 4 floats


			/***************************************************************
			 * Overloading oprators                                        *
			 ***************************************************************/

			Color operator + (const float)const;
			Color operator + (const Color&)const;

			Color operator - (const float)const;
			Color operator - (const Color&)const;

			Color operator * (const float)const;
			Color operator * (const Color&)const ;

			/***************************************************************
			 * Test two colors for equality                                *
			 * returns true if the R, G, B and A components are all equal. *
			 * *************************************************************/
			 bool operator == (const Color&)const;
			 bool operator != (const Color&)const;

			 /**************************************************************
			  * some out put function just to ease debuging                *
			  **************************************************************/
			 friend ostream& operator << (ostream& Output, Color &color)
			 {
				 return (Output << " Red = " << color.r << ", Green = " << color.g <<" , Blue = " << color.b << " , Alpha = " << color.a << endl);
			 }
			 /****************************************************************
			  * Othere sutff should be added to the classe                   *
			  ****************************************************************/
			 Color invert(); //invert the color example black it's invert is white
			 Color clamping(); // make sure that we have value beteween 0 and 1

			 // TODO ...............
	};

	/****************************************************************
	 *
	 * Some usefull inline function
	 *
	 ***************************************************************/
	inline
	Color Lerping(float t,const Color &A,const Color &B) // c(t) = (1 − t)c 1 + tc 2 ,t ∈ [0, 1] linear interpolation
	{
		Color InterpolatedColor; // this a reslut of the lerping

		float inverT = 1 - t ;
		float r = inverT * A.get()[0] +  t * B.get()[0]; // out of the classe we should use our setters and getters
		float g = inverT * A.get()[1] +  t * B.get()[1];
		float b = inverT * A.get()[2] +  t * B.get()[2];
		float a = inverT * A.get()[3] +  t * B.get()[3];

		// we finaly set our interpolated color and return it as result

		InterpolatedColor.set(r,g,b,a);

		return InterpolatedColor;
	}


} /* namespace RP */

#endif /* COLOR_H_ */
