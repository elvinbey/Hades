#pragma once
#include "ldasm.h"
#include "Hook.h"
#include "winstructs.h"
#include "memory.h"
#include "cr0.h"
#include <intrin.h>

namespace HadesKernel {
	namespace Mem {
		namespace Hook {
			class Detour : public Hook {
			private:
				static int constexpr length_jmp = 14;

				//PUSH lowerPart
				//MOV [RSP+4], higherPart
				//RET
				const char* jmp_machine_code = "\x68\x00\x00\x00\x00\xC7\x44\x24\x04\x00\x00\x00\x00\xC3";
				int trampoline_size = 0;
				UINT8* trampoline;

				BOOLEAN isHooked = FALSE;
			public:
				Detour(UINT8* src, UINT8* dst);
				~Detour();

				void hook();
				void unhook();

				UINT8* getTrampoline();
			};
		}
	}
}