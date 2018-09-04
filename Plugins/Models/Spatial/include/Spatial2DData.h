#include "Data.h"
#include "Vector2.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Spatial2DData : public Efficio::Data
			{
			public:
				Spatial2DData();
				Spatial2DData(float x, float y);
				Spatial2DData(Vector2 vector);
				~Spatial2DData();
				Vector2 Position();

				virtual std::string GetDataType() override;
			private:
				Vector2 position;
			};
		}
	}
}