#pragma once
#include <string>
#include <fstream>
#include "PEFile.h"

namespace Hades {
	namespace PE {
		class PEAnalyser {
		private:
			static bool isValid();
		public:
			static PEFile* load(std::string path);
			static PEFile* loadFromMemory();
		};
	}
}