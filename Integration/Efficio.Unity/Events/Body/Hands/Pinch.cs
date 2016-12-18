using Efficio.Unity.MessageBus;
using Efficio.Unity.MessageBus.Body.Hands;
using System;
using System.Collections;

namespace Efficio.Unity.Events.Body.Hands
{
    public abstract class Pinch : MessageHandler
    {
        public int DelayAfterPinch;

        DateTime resetTime;
        bool coroutineStarted = false;

        protected virtual MessageType[] messageTypes
        {
            get
            {
                return new MessageType[] {
                    MessageType.LeftHandIndexMiddlePinch,
                    MessageType.LeftHandIndexPinkyPinch,
                    MessageType.LeftHandIndexRingPinch,
                    MessageType.LeftHandMiddlePinkyPinch,
                    MessageType.LeftHandMiddleRingPinch,
                    MessageType.LeftHandRingPinkyPinch,
                    MessageType.LeftHandThumbIndexPinch,
                    MessageType.LeftHandThumbMiddlePinch,
                    MessageType.LeftHandThumbPinkyPinch,
                    MessageType.LeftHandThumbRingPinch,
                    MessageType.RightHandIndexMiddlePinch,
                    MessageType.RightHandIndexPinkyPinch,
                    MessageType.RightHandIndexRingPinch,
                    MessageType.RightHandMiddlePinkyPinch,
                    MessageType.RightHandMiddleRingPinch,
                    MessageType.RightHandRingPinkyPinch,
                    MessageType.RightHandThumbIndexPinch,
                    MessageType.RightHandThumbMiddlePinch,
                    MessageType.RightHandThumbPinkyPinch,
                    MessageType.RightHandThumbRingPinch,
                };
            }
        }

        public override MessageType[] MessageTypes
        {
            get
            {
                return messageTypes;
            }
        }

        public abstract void HandlePinch(PinchMessage message);

        public abstract void OnPinchEnd();

        public override void HandleMessage(Message message)
        {
            HandlePinch((PinchMessage)message);

            // Set time to declare pinch has ended
            resetTime = DateTime.Now.AddMilliseconds(DelayAfterPinch);

            // If pinch end timeout coroutine has not yet started
            if (!coroutineStarted)
            {
                coroutineStarted = true;
                StartCoroutine(PinchEndTimer(OnPinchEnd));
            }
        }

        private IEnumerator PinchEndTimer(Action action)
        {
            while (DateTime.Now < resetTime)
            {
                yield return null;
            }

            coroutineStarted = false;
            action();
        }
    }
}
