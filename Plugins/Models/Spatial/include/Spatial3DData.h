#include "Data.h"
#include "Vector3.h"
#include <memory>

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Spatial3DData : public Efficio::Data
			{
			public:
				Spatial3DData();
				Spatial3DData(float x, float y, float z);
				Spatial3DData(Vector3 position);
				~Spatial3DData();

				Vector3 Position();

				virtual std::string GetDataType() override;
			private:
				Vector3 position;
			};
		}
	}
}