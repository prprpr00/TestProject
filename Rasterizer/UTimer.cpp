#include "UTimer.h"
#include<iostream>

UTimer::UTimer() 
	:
	beginTime(clock()),
	lastTime(clock())
{}

clock_t UTimer::GetClock() noexcept
{
	return clock();
}

bool UTimer::IsPeek() noexcept
{	
	clock_t nowTime = clock();
	return (nowTime - lastTime >= framePeek) ? lastTime = nowTime, true : false;
}
