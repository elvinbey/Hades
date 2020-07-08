#include "RawData.h"

using Hades::Communication::Raw::RawData;

RawData::RawData(uint32_t type, uint64_t size) {
	this->type = type;
	this->size = size;
}