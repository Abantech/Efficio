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
				Spatial3DData(Vector3 position);
				~Spatial3DData();

				bool HasPosition();
				Vector3 GetPosition();

				virtual std::string GetDataType() override;
			private:
				std::shared_ptr<Vector3> position;
			};
		}
	}
}