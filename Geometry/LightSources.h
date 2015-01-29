/*************************************************************************************
 * LightSources.h                                                                    *
 *                                                                                   *
 *  Created on: Jan 29, 2015                                                         *
 *      Author: hakosoft saouli                                                      *
 *      this classe will be the holdetr for all the lights in the scene. every render*
 *      algorithm implimented will take it as an argument                            *
 *************************************************************************************/

#ifndef LIGHTSOURCES_H_
#define LIGHTSOURCES_H_

namespace RP
{

	class LightSources
	{
		public:
			LightSources();
			virtual ~LightSources();
	};

} /* namespace RP */

#endif /* LIGHTSOURCES_H_ */
