using Efficio.Net;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.MessageBus
{
    public class ButtonPressedMessage : Message
    {
        ButtonType buttonType;

        public ButtonType ButtonType
        {
            get
            {
                return buttonType;
            }
        }

        public ButtonPressedMessage(GearVRAction gearVRAction)
        {
            this.buttonType = gearVRAction.ButtonType;
        }
    }
}