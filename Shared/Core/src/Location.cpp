#include "Location.h"
#include <stdexcept>
#include<stdio.h>

#if _WINDLL
#define ThrowIfAble(x) throw x
#else
#define ThrowIfAble(x)
#endif

Efficio::Data::Positional::Location::Location(float latitude, float longitude) : latitude(latitude), longitude(longitude)
{
	if (latitude < -180)
	{
		ThrowIfAble(std::invalid_argument("Latitude argument cannot be less than -180"));
	}

	if (latitude > 180)
	{
		ThrowIfAble(std::invalid_argument("Latitude argument cannot be more than 180"));
	}

	if (longitude < -90)
	{
		ThrowIfAble(std::invalid_argument("Longitude argument cannot be less than -90"));
	}

	if (longitude > 90)
	{
		ThrowIfAble(std::invalid_argument("Longitude argument cannot be more than 90"));
	}
}