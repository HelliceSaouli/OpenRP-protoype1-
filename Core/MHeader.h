/**************************************************************************************
 * MHeader.h
 *
 *  Created on: Nov 10, 2014
 *      Author: Saouli ABdelhak
 *
 * The main header file for the  platform
 **************************************************************************************/




#ifndef MHEADER_H_
#define MHEADER_H_

/**************************************************************************************
 *
 * Include system Headers
 *
 *************************************************************************************/
#include <cmath>
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits>
#include <cassert>
#include <string>
#include <vector>

using namespace std;
/* Define some Constant here */

#ifndef PI
# define PI 3.1415926535897932384626433832795                          //The number PI used in math
#endif

#ifndef LOG2
# define LOG2 0.69314718055994530941723212145818                       // The log
#endif

/*************************************************************************************
 *
 *  Include OpenGL Headers
 *
 ************************************************************************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

/*************************************************************************************
 *
 *  Include Other Headers
 *
 ************************************************************************************/

	// TO DO.............

/* Define some helpful MACRO */
	// TO DO.............
#ifndef SWAP
# define SWAP(a,b,c) ((c) = (a), (a) = (b),  (b) = (c))                  // Swapping between a and b
#endif

#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))							 // the min between a and b
#endif

#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))							// the max between a and b
#endif

#ifndef CLAMP
# define CLAMP(x,min,max) ( (x) < (min) ? (min) : ((x > max) ?  (max) : (x)) ) // this will help a lot for example clamping color  when add them togthere
#endif

/*************************************************************************************
 *
 *  Include  some usful inline fucntion
 *
 ************************************************************************************/
inline
float DegreeToRad(float Angle)
{
	return (Angle  * ( PI / 180.00));
}

inline
float cotangent(float Angle)
{
	return (1/tan(Angle));
}

#endif /* MHEADER_HPP_ */
