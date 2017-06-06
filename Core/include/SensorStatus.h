#pragma once

namespace Efficio
{
	/// The device statii
	enum class SensorStatus
	{
		Unknown,
		Uninitialized,
		Disabled,
		Faulted,
		Disconnecting,
		Disconnected,
		Connecting,
		Connected
	};
}