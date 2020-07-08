#pragma once
#include "ldasm.h"
#include "Hook.h"
#include <iostream>
#include "WinThread.h"

namespace Hades {
	namespace Mem {
		namespace Hook {
			class Detour : public Hook {
			private:
				static int constexpr length_jmp = 14;

				//PUSH lowerPart
				//MOV [RSP+4], higherPart
				//RET
				//Investigate in this issue
				const char* jmp_machine_code = "\x68\x00\x00\x00\x00\xC7\x44\x24\x04\x00\x00\x00\x00\xC3";


				int trampoline_size = 0;
				uint8_t* trampoline;
			public:
				Detour(uint8_t* src, uint8_t* dst);

				void hook();
				void unhook();

				uint8_t* getTrampoline();
			};
		}
	}
}