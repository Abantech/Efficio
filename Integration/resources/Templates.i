%template(EventCollection) std::vector<std::shared_ptr<Efficio::Events::Event>>;
%template(SensorCollection) std::vector<std::shared_ptr<Efficio::Sensors::Sensor>>;
%template(GestureCollection) std::vector<std::shared_ptr<Efficio::InputRecognition::Gesture>>;
%template(DataCollection) std::vector<std::shared_ptr<Efficio::Data::Data>>;
%template(JointCollection) std::vector<Efficio::Models::Body::Joint>;
%template(FingerCollection) std::array<Efficio::Models::Body::Finger,5>;
%template(AssetCollection) std::vector<std::shared_ptr<Efficio::Asset>>;