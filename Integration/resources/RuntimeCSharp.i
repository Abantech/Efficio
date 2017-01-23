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

