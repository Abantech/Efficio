namespace Efficio.Unity.MessageBus
{
    public enum MessageType
    {
        Unknown,

        // Pinch
        RightHandThumbIndexPinch,
        RightHandThumbMiddlePinch,
        RightHandThumbRingPinch,
        RightHandThumbPinkyPinch,
        RightHandIndexMiddlePinch,
        RightHandIndexRingPinch,
        RightHandIndexPinkyPinch,
        RightHandMiddleRingPinch,
        RightHandMiddlePinkyPinch,
        RightHandRingPinkyPinch,
        LeftHandThumbIndexPinch,
        LeftHandThumbMiddlePinch,
        LeftHandThumbRingPinch,
        LeftHandThumbPinkyPinch,
        LeftHandIndexMiddlePinch,
        LeftHandIndexRingPinch,
        LeftHandIndexPinkyPinch,
        LeftHandMiddleRingPinch,
        LeftHandMiddlePinkyPinch,
        LeftHandRingPinkyPinch,

        // Wrist Rotation
        RightHandSupine,
        LeftHandSupine,

        // Internal
        EfficioStarted,
        SensorConnected,
        SensorFaulted,
        SensorDisconnected,
        ButtonPressed,
    }
}