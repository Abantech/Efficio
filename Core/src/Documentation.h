#pragma once

/// <summary>
/// Root namespace
/// </summary>
namespace Efficio
{
	/// <summary>
	/// Classes for configuring sensors
	/// </summary>
	namespace Configuration {}

	/// <summary>
	/// Efficio representation device-agnostic data
	/// </summary>
	namespace Data
	{
		/// <summary>
		/// Efficio representation device-agnostic positional data
		/// </summary>
		namespace Positional {}
	}

	/// <summary>
	/// Actionable events in the Efficio engine
	/// </summary>
	namespace Events
	{
		/// <summary>
		/// All events that occur within the Efficio system
		/// </summary>
		namespace Internal
		{

		}
	}

	/// <summary>
	/// Events related to input recognition and processing
	/// </summary>
	namespace InputRecognition
	{
		/// <summary>
		/// Events related to human-related input recognition and processing
		/// </summary>
		namespace Human
		{
			/// <summary>
			/// Events related to human hand related input recognition and processing
			/// </summary>
			namespace Hands {}
		}
	}

	/// <summary>
	/// Contains all models for representing various data types
	/// </summary>
	namespace Models
	{
		/// <summary>
		/// Model of the human body
		/// </summary>
		namespace Body {}
	}

	/// <summary>
	/// Data collection devices
	/// </summary>
	namespace Sensors
	{
		/// <summary>
		/// Sensors for measuring human input
		/// </summary>
		namespace Body
		{

		}
	}
}
