#pragma once
#include<stdio.h>
#include"WindowInit.h"
#define SCREEN_SIZE 6192
#define WIDTH 129
#define HEIGHT 48
#define POS(x,y) y * 129 + x

class Renderer 
{
private:
	HANDLE hStdOut;
	char screenBuffer[SCREEN_SIZE]{ 0 };
	char depthBuffer[SCREEN_SIZE]{ 0 };

public:
	Renderer() noexcept;
	~Renderer() noexcept = default;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	void Draw() noexcept;
	void Rasterization() noexcept;
	void CreateDepthBuffer(COORD& pos) noexcept;
};