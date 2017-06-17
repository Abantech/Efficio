#pragma once

#include "Asset.h"

namespace Efficio
{
	namespace Assets
	{
		/// <summary>
		/// Wrapper for the Leap Motion hand sensor.  More information about this device can be found at https://www.leapmotion.com/
		/// </summary>
		/// <seealso cref="Asset" />
		class LeapMotion : public Efficio::Asset
		{
		public:
			LeapMotion();
			~LeapMotion();
		};
	}
}