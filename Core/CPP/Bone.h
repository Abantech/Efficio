#pragma once

#include "Joint.h"
#include "BoneTypes.h"
#include "Vector3.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// <summary>
			/// A segment between two joints
			/// </summary>
			extern class DLLEXPORT Bone
			{
			public:
				/// <summary>
				/// Initializes a new instance of the <see cref="Bone"/> class.
				/// </summary>
				/// <param name="proximalJoint">The proximal joint.</param>
				/// <param name="distalJoint">The distal joint.</param>
				Bone(Joint proximalJoint, Joint distalJoint);

				/// <summary>
				/// Finalizes an instance of the <see cref="Bone"/> class.
				/// </summary>
				~Bone();

				/// <summary>
				/// The proximal joint
				/// </summary>
				const Joint ProximalJoint;

				/// <summary>
				/// The distal joint
				/// </summary>
				const Joint DistalJoint;

				/// <summary>
				/// The bone type
				/// </summary>
				const BoneType Type;

				/// <summary>
				/// Calculates length of the bone from joint to joint
				/// </summary>
				/// <returns>A float representing the length of the bone</returns>
				const float Length();

				/// <summary>
				/// The width of the bone
				/// </summary>
				/// <returns></returns>
				const float Width();

				// TODO change to quaternion
				const int Rotation();

				// TODO figure out what this is. Leap uses it
				const int Basis();

				/// <summary>
				/// Calculates the center of the bone
				/// </summary>
				/// <returns>A vector representing the center of the bone</returns>
				const Vector3 Center();


				const Vector3 Direction();

			};
		}
	}
}