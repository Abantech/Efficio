#include "Frame.h"

Efficio::Frame::Frame() {

}

Efficio::Frame::~Frame() {

}

Efficio::Data::Datum* Efficio::Frame::GetData(Efficio::Data::DatumType dataType)
{
	return dataCollection.at(dataType);
}

void Efficio::Frame::AddData(Efficio::Data::Datum* datum)
{
	dataCollection.emplace(datum->GetDatumType(), datum);
}
