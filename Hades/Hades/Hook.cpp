#include "Hook.h"

using Hades::Mem::Hook::Hook;
using Hades::Mem::Hook::HookType;

Hook::Hook(HookType type, uint8_t* src, uint8_t* dst) {
	this->type = type;
	this->src = src;
	this->dst = dst;
}

HookType Hook::getType() {
	return this->type;
}

uint8_t* Hook::getDst() {
	return this->dst;
}

uint8_t*Hook::getSrc() {
	return this->src;
}