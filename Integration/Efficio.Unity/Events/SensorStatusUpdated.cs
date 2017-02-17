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

        public override void HandleMessage(Message message)
        {
            this.HandleSensorStatusUpdated((SensorUpdatedMessage)message);
        }

        public abstract void HandleSensorStatusUpdated(SensorUpdatedMessage sensorUpdatedMesage);
    }

    public abstract class SensorConnected : SensorStatusUpdated
    {
        public override void HandleSensorStatusUpdated(SensorUpdatedMessage sensorUpdatedMesage)
        {
            if (sensorUpdatedMesage.Type == MessageType.SensorConnected)
            {
                this.OnSensorConnected(sensorUpdatedMesage);
            }
        }

        public abstract void OnSensorConnected(SensorUpdatedMessage sensorConnectededMesage);
    }

    public abstract class SensorFaulted : SensorStatusUpdated
    {
        public override void HandleSensorStatusUpdated(SensorUpdatedMessage sensorUpdatedMesage)
        {
            if (sensorUpdatedMesage.Type == MessageType.SensorFaulted)
            {
                this.OnSensorFaulted(sensorUpdatedMesage);
            }
        }

        public abstract void OnSensorFaulted(SensorUpdatedMessage sensorFaultedMesage);
    }


    public abstract class SensorDisconnected : SensorStatusUpdated
    {
        public override void HandleSensorStatusUpdated(SensorUpdatedMessage sensorUpdatedMesage)
        {
            if (sensorUpdatedMesage.Type == MessageType.SensorDisconnected)
            {
                this.OnSensorDisconnected(sensorUpdatedMesage);
            }
        }

        public abstract void OnSensorDisconnected(SensorUpdatedMessage sensorDisconnectededMesage);
    }

}
