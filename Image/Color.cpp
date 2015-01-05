/*
 * Color.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: hakosoft saouli
 */

#include "Color.h"

namespace RP
{

	/********************************************************************************
	 * Static colors name so that the user can set the color he want to use by it's *
	 * name . I'am not putting all the colors right know but i will add them later  *
	 * example : Color Value = Color:: white
	 * this will be a long proccess OMG XD                                       *
	 ********************************************************************************/

	const Color Color::white(1.0,1.0,1.0,1.0);
	const Color Color::Azure(0.941176,1.0,1.0,1.0);
	const Color Color::whitesmook(0.960784,0.960784,0.960784,1.0);

	const Color Color::gray(0.5,0.5,0.5,1.0);
	const Color Color::silver(0.752941,0.752941,0.752941,1.0);
	const Color Color::slategray(0.439216,0.501961,0.564706,1.0);
	const Color Color::black(0.0,0.0,0.0,1.0);

	const Color Color::red(1.0,0.0,0.0,1.0);
	const Color Color::crimson(0.862745,0.0784314,0.235294,1.0);
	const Color Color::darkred(0.545098,0.0,0.0,1.0);

	const Color Color::pink(1.0,0.752941,0.796078,1.0);
	const Color Color::lightpink(1.0,0.713726,0.756863,1.0);
	const Color Color::hotpink(1.0,0.411765,0.705882,1.0);

	const Color Color::orange(1.0,0.647059,0.0,1.0);
	const Color Color::colar(1.0,0.498039,0.313726,1.0);
	const Color Color::orangered(1.0,0.270588,0.0,1.0);

	const Color Color::yellow(1.0,1.0,0.0,1.0);
	const Color Color::gold(1.0,0.843137,0.0,1.0);

	const Color Color::brown(0.647059,0.164706,0.164706,1.0);
	const Color Color::maroon(0.501961,0.0,0.0,1.0);

	const Color Color::green(0.0,1.0,0.0,1.0);
	const Color Color::lime(0.196078,0.803922,0.196078,1.0);
	const Color Color::darkgreen(0.0,0.392157,0.0,1.0);

	const Color Color::blue(0.0,0.0,1.0,1.0);
	const Color Color::aqua(0.0,1.0,1.0,1.0);
	const Color Color::darkblue(0.0,0.0,0.545098,1.0);

	const Color Color::purple(0.501961,0.0,0.501961,1.0);
	const Color Color::magenta(1.0,0.0,1.0,1.0);
	const Color Color::indgo(0.294118,0.0,0.509804,1.0);

	Color::Color()
	{
		this->r = 0;
		this->g = 0;
		this->b = 0;

		this->a = 1;
	}

	Color::Color(float red, float green, float blue, float Alpha)
	{
		this->r = red;
		this->g = green;
		this->b = blue;

		this->a = Alpha;
	}

	Color::Color(Vec3f RGB, float Alpha)
	{
		this->r = RGB[0];
		this->g = RGB[1]; // i could use the getter function in vector  RGB.getX()
		this->b = RGB[2];

		this->a = Alpha;
	}

	Color::Color(Vec4f RGBA)
	{
		this->r = RGBA[0];
		this->g = RGBA[1];
		this->b = RGBA[2];

		this->a = RGBA[3];
	}

	Color::Color(Color &color)
	{
		this->r = color.r;
		this->g = color.g;
		this->b = color.b;

		this->a = color.a;
	}
	Color::~Color()
	{
		// TODO Auto-generated destructor stub
	}

	/*****************************************************************
	 *                                                               *
     * the get and set function   this is for  the over classe can   *
     * use it                                                        *
     *****************************************************************/

	void Color::set(float r,float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;

		this->a = a;
	}

	Vec4f Color::get() // return a vector that contain the color
	{
		Vec4f RGBA;
		RGBA[0] = this->r;
	    RGBA[1] = this->g;
	    RGBA[2] = this->b;

	    RGBA[3] = this->a;

	    return RGBA;
	}
	 /****************************************************************
	  * Othere sutff should be added to the classe                   *
	  ****************************************************************/

	Color Color::invert() // invert the color like the the invert white is black
	{
		this->r = 1-this->r;
		this->g = 1-this->g;
		this->b = 1-this->b;

		return (*this);
	}

	/***************************************************************************
	 *Clamping your color in case they're too high or low for                  *
	 *their types, in case you go negative or too use values that are too high,*
	 *like 2.0 >1.0  we that 2 can't be a color value                          *
	 ***************************************************************************/
	 Color Color::clamping()
	 {
			this->r = CLAMP(this->r,0.0,1.0);
			this->g = CLAMP(this->g,0.0,1.0);
			this->b = CLAMP(this->b,0.0,1.0);

			this->a = CLAMP(this->a,0.0,1.0);
		 return (*this);
	 }


	/***************************************************************
	 * Overloading oprators                                        *
	 * we wanna add some color to each othere or substruct or scal *
	 * it                                                          *
	 ***************************************************************/
	 Color Color::operator +(float Value)
	 {
		 Color Result;

		  Result.r = r + Value;
		  Result.g = g + Value;
		  Result.b = b + Value;

		  Result.a = a + Value; // do the transperncy accumlate ?
		  Result.clamping(); // may be i  have error here Oo ????? if any things goes wrong take look here first

		  return Result;
	 }

	 Color Color::operator -(float Value)
	 {
		 Color Result;

		  Result.r = r - Value;
		  Result.g = g - Value;
		  Result.b = b - Value;

		  Result.a = a - Value;
		  Result.clamping();

		  return Result;
	 }

	 Color Color::operator *(float Value)
	 {
		 Color Result;

		  Result.r = r * Value;
		  Result.g = g * Value;
		  Result.b = b * Value;

		  Result.a = a * Value;
		  Result.clamping();

		  return Result;
	 }

	 Color Color::operator +(Color color)
	 {
		 Color Result;

		  Result.r = r + color.r;
		  Result.g = g + color.g;
		  Result.b = b + color.b;

		  Result.a = a + color.a;
		  Result.clamping(); // may be i  have error here Oo ????? if any things goes wrong take look here first

		  return Result;
	 }

	 Color Color::operator -(Color color)
	 {
		 Color Result;

		  Result.r = r - color.r;
		  Result.g = g - color.g;
		  Result.b = b - color.b;

		  Result.a = a - color.a;
		  Result.clamping(); // may be i  have error here Oo ????? if any things goes wrong take look here first

		  return Result;
	 }

	 Color Color::operator *(Color color)
	 {
		 Color Result;

		  Result.r = r * color.r;
		  Result.g = g * color.g;
		  Result.b = b * color.b;

		  Result.a = a - color.a;
		  Result.clamping(); // may be i  have error here Oo ????? if any things goes wrong take look here first

		  return Result;
	 }

		/***************************************************************
		 * Test two colors for equality                                *
		 * returns true if the R, G, B and A components are all equal. *
		 * *************************************************************/

	 bool Color::operator ==(Color color)
		{
		 	 return (r == color.r) && (g == color.g) && (b == color.b) && (a == color.a);
		}

	 bool Color::operator !=(Color color)
		{
		  return (r != color.r) || (g != color.g) || (b != color.b) || (a != color.a);
		}

} /* namespace RP */
