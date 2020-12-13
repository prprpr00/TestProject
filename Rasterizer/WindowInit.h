#pragma once
#include<windows.h>

class WindowInit
{
private:
	HANDLE hStdOut;
	HANDLE hStdIn;
	static WindowInit wiInstance;

private:
	WindowInit() noexcept;
	~WindowInit() noexcept;
	WindowInit(const WindowInit&) = delete;
	WindowInit& operator=(const WindowInit&) = delete;

public:
	static const WindowInit& GetWIInstance() noexcept;
	static HANDLE& GetStdOutHandle() noexcept;
	static HANDLE& GetStdInHandle() noexcept;
};

