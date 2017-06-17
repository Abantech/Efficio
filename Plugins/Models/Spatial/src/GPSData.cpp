#include "GPSData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			GPSData::GPSData() : Efficio::Data() { }

			GPSData::~GPSData() { }

			float GPSData::GetAccuracy()
			{
				return 0;
			}

			double GPSData::GetLatitude()
			{
				return 0;
			}

			double GPSData::GetLongitude()
			{
				return 0;
			}

			float GPSData::GetAltitudeAccuracy()
			{
				return 0;
			}

			double GPSData::GetAltitude()
			{
				return 0;
			}


			float GPSData::GetSpeedAccuracy()
			{
				return 0;
			}

			double GPSData::GetSpeed()
			{
				return 0;
			}

			double GPSData::GetTime()
			{
				return 0;
			}

			float GPSData::GetBearingAccuracy()
			{
				return 0;
			}

			float GPSData::GetBearing()
			{
				return 0;
			}


			std::string GetDataType()
			{
				return "GPS";
			}
		}
	}
}