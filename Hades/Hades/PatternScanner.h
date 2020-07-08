#pragma once
#include <Windows.h>
#include <stdint.h>
#include <string>
#include <algorithm>
#include "PEFile.h"

namespace Hades {
	namespace Mem {
		class PatternScanner {
		private:
			static uint8_t* search_internal(byte* start, int size, const char* pattern, const char* mask);
		public:
			static uint8_t* search(std::string moduleName, const char* pattern, const char* mask);
			static uint8_t* search(const char* pattern, const char* mask);
		};
	}
}