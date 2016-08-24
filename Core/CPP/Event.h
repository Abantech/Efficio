#pragma once

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio {
	/// The abstract class for all events within the Efficio system. Events are raised when anything notable happens within the Efficio ecosystem.
	extern class DLLEXPORT Event
	{
	public:
		Event();
		virtual ~Event();
	};
}