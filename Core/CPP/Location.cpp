#include "Location.h"
#include <stdexcept>

Efficio::Models::Positional::Location::Location(float latitude, float longitude) : latitude(latitude), longitude(longitude)
{
	if (latitude < -180)
	{
		throw std::invalid_argument("Latitude argument cannot be less than -180");
	}

	if (latitude > 180)
	{
		throw std::invalid_argument("Latitude argument cannot be more than 180");
	}

	if (longitude < -90)
	{
		throw std::invalid_argument("Longitude argument cannot be less than -90");
	}

	if (longitude > 90)
	{
		throw std::invalid_argument("Longitude argument cannot be more than 90");
	}
}