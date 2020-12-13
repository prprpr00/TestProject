#pragma once
#include<time.h>

class UTimer
{
private:
	clock_t beginTime;
	clock_t lastTime;
	const int framePeek = 55;

public:
	UTimer();
	~UTimer() = default;
	UTimer(const UTimer&) = delete;
	UTimer& operator=(const UTimer&) = delete;
	clock_t GetClock() noexcept;
	bool IsPeek() noexcept;
};

