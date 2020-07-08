#include "WinThread.h"

std::vector<THREADENTRY32> Hades::WinThread::getThreadsInternal(bool ownOnly) {
	std::vector<THREADENTRY32> vec;
	HANDLE threadHandle = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	if (threadHandle == INVALID_HANDLE_VALUE)
		return vec;

	int pid = GetCurrentProcessId();

	THREADENTRY32 threadEntry;
	threadEntry.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(threadHandle, &threadEntry)) {
		do {
			if (ownOnly && threadEntry.th32OwnerProcessID != pid)
				continue;

			vec.push_back(threadEntry);
		} while (Thread32Next(threadHandle, &threadEntry));
	}

	return vec;
}

std::vector<THREADENTRY32> Hades::WinThread::getThreads() {
	return Hades::WinThread::getThreadsInternal(false);
}

std::vector<THREADENTRY32> Hades::WinThread::getOwnThreads() {
	return Hades::WinThread::getThreadsInternal(true);
}

void Hades::WinThread::suspendThreads() {
	auto threads = Hades::WinThread::getOwnThreads();
	auto currentThreadId = GetCurrentThreadId();

	for (auto thread : threads) {
		if (thread.th32ThreadID == currentThreadId)
			continue;

		HANDLE threadHandle = OpenThread(THREAD_SUSPEND_RESUME, 0, thread.th32ThreadID);
		if (threadHandle) {
			SuspendThread(threadHandle);
		}

		CloseHandle(threadHandle);
	}
}

void Hades::WinThread::resumeThreads() {
	auto threads = Hades::WinThread::getOwnThreads();

	for (auto thread : threads) {
		HANDLE threadHandle = OpenThread(THREAD_SUSPEND_RESUME, 0, thread.th32ThreadID);
		if (threadHandle) {
			while(ResumeThread(threadHandle) > 0)
				ResumeThread(threadHandle);
		}

		CloseHandle(threadHandle);
	}
}