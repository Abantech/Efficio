%module EfficioRuntime
%{

%}
  
%typemap(csattributes) Efficio::Frame "[System.Runtime.Serialization.DataContract]"
%typemap(cscode) Efficio::Frame %{
    [System.Runtime.Serialization.DataMember]
    public DataCollection Data
    {
        get { return this.GetData(); }
	}
	
	[System.Runtime.Serialization.DataMember]
    public EventCollection Events
    {
        get { return this.GetEvents(); }
	}
	
	public System.Collections.Generic.IEnumerable<T> GetDataOfType<T>()
        {
            System.Collections.Generic.List<T> collection = new System.Collections.Generic.List<T>();
            DataType dataType = GetDataTypeForType<T>();

            foreach (var datum in this.Data)
            {
                if (datum.GetDataType() == dataType)
                {
                    collection.Add(SWIGHelper.CastTo<T>(datum));
                }
            }

            return collection;
        }

        public DataType GetDataTypeForType<T>()
        {
            DataType dataType = DataType.None;

            System.Type typeParameterType = typeof(T);

            if (typeParameterType == typeof(HandData))
            {
                dataType = DataType.Hand;
            }

            if (typeParameterType == typeof(FaceData))
            {
                dataType = DataType.Face;
            }

            return dataType;
        }
%}
%csattributes Efficio::Frame::ID "[System.Runtime.Serialization.DataMember]"
%csattributes Efficio::Frame::DeltaTime "[System.Runtime.Serialization.DataMember]"

%typemap(csattributes) Efficio::Events::Event "[System.Runtime.Serialization.DataContract]"
%csattributes Efficio::Events::Event::ID "[System.Runtime.Serialization.DataMember]"
%csattributes Efficio::Events::Event::Source "[System.Runtime.Serialization.DataMember]"
%typemap(cscode) Efficio::Events::Event %{
    [System.Runtime.Serialization.DataMember]
    public EventType EventType
    {
        get { return this.GetEventType(); }
        set { }
    }
%}


%include <Efficio.i>

