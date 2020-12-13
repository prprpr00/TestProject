#include "WindowInit.h"

WindowInit WindowInit::wiInstance;
WindowInit::WindowInit() noexcept
	:
	hStdOut(GetStdHandle(STD_OUTPUT_HANDLE)),
	hStdIn(GetStdHandle(STD_INPUT_HANDLE))
{}

WindowInit::~WindowInit() noexcept
{
	CloseHandle(hStdOut);
	CloseHandle(hStdIn);
}

const WindowInit& WindowInit::GetWIInstance() noexcept
{
	return wiInstance;
}

HANDLE& WindowInit::GetStdOutHandle() noexcept
{
	return wiInstance.hStdOut;
}

HANDLE& WindowInit::GetStdInHandle() noexcept
{
	return wiInstance.hStdIn;
}
