using Efficio.Unity.MessageBus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Efficio.Unity.Events
{
    public abstract class SensorStatusUpdated : MessageHandler
    {
        protected MessageType sensorMessageType;

        public override MessageType[] MessageTypes
        {
            get
            {
                return new MessageType[] { this.sensorMessageType };
            }
        }

        public override void HandleMessage(IMessage message)
        {
            this.HandleSensorStatusUpdated((ISensorUpdatedMessage)message);
        }

        public abstract void HandleSensorStatusUpdated(ISensorUpdatedMessage sensorUpdatedMesage);
    }

    public abstract class SensorFaulted : SensorStatusUpdated
    {
        public override void HandleSensorStatusUpdated(ISensorUpdatedMessage sensorUpdatedMesage)
        {
            if (sensorUpdatedMesage.GetMessageType == MessageType.SensorFaulted)
            {
                this.OnSensorFaulted(sensorUpdatedMesage);
            }
        }

        public abstract void OnSensorFaulted(ISensorUpdatedMessage sensorFaultedMesage);
    }


    public abstract class SensorDisconnected : SensorStatusUpdated
    {
        public override void HandleSensorStatusUpdated(ISensorUpdatedMessage sensorUpdatedMesage)
        {
            if (sensorUpdatedMesage.GetMessageType == MessageType.SensorDisconnected)
            {
                this.OnSensorDisconnected(sensorUpdatedMesage);
            }
        }

        public abstract void OnSensorDisconnected(ISensorUpdatedMessage sensorDisconnectededMesage);
    }

}
