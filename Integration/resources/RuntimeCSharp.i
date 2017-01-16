%module EfficioRuntime
%{

%}
  
%typemap(csattributes) Efficio::Frame "[System.Runtime.Serialization.DataContract]"
%typemap(cscode) Efficio::Frame %{
	[System.Runtime.Serialization.DataMember]
	public DataCollection Data {
		get { return this.GetData(); }
	}
%}

%include <Efficio.i>

