#include "Hook.h"

using HadesKernel::Mem::Hook::Hook;
using HadesKernel::Mem::Hook::HookType;

Hook::Hook(HookType type, UINT8* src, UINT8* dst) {
	this->type = type;
	this->src = src;
	this->dst = dst;
}

HookType Hook::getType() {
	return this->type;
}

UINT8* Hook::getDst() {
	return this->dst;
}

UINT8*Hook::getSrc() {
	return this->src;
}