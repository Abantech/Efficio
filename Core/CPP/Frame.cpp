#include "Frame.h"

Efficio::Frame::Frame() {

}

Efficio::Frame::~Frame() {

}

Efficio::Data::Data* Efficio::Frame::GetData(Efficio::Data::DataType dataType)
{
	return dataCollection.at(dataType);
}

void Efficio::Frame::AddData(Efficio::Data::Data* data)
{
	dataCollection.emplace(data->GetDataType(), data);
}
