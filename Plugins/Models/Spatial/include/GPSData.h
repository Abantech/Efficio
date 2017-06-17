#include "Data.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class GPSData : public Efficio::Data
			{
			public:
				GPSData();
				~GPSData();
				float GetAccuracy();
				double GetLatitude();
				double GetLongitude();

				float GetAltitudeAccuracy();
				double GetAltitude();

				float GetSpeedAccuracy();
				double GetSpeed();
				double GetTime();

				float GetBearingAccuracy();
				float GetBearing();


				virtual std::string GetDataType() override;
			private:
				double latitude;
				double longitude;
				double altitude;
				double speed;
				double time;
				float bearing;
			};
		}
	}
}