using Efficio.Unity.MessageBus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.Events
{
    public abstract class ButtonPressed : MessageHandler
    {
        public override MessageType[] MessageTypes
        {
            get
            {
                return new MessageType[] { MessageType.ButtonPressed };
            }
        }

        public override void HandleMessage(Message message)
        {
            this.HandleButtonPress((ButtonPressedMessage)message);
        }

        public abstract void HandleButtonPress(ButtonPressedMessage message);
    }

    public abstract class BackButtonPress : ButtonPressed
    {
        public override void HandleButtonPress(ButtonPressedMessage message)
        {
            if (message.ButtonType == Net.ButtonType.Back)
            {
                this.BackButtonPressed(message);
            }
        }

        public abstract void BackButtonPressed(ButtonPressedMessage message);
    }
}
