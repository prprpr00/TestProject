#include "Renderer.h"

Renderer::Renderer() noexcept 
	:
	hStdOut(WindowInit::GetStdOutHandle())
{
	screenBuffer[SCREEN_SIZE - 1] = '\n';
}

void Renderer::Draw() noexcept
{
	fprintf(stdout, "%s", screenBuffer);
	SetConsoleCursorPosition(hStdOut, { 0,0 });
}

void Renderer::Rasterization() noexcept
{
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			if (depthBuffer[POS(i, j)])
				screenBuffer[POS(i, j)] = '@';
			else
				screenBuffer[POS(i, j)] = ' ';
			depthBuffer[POS(i, j)] = 0;
		}
	}
}

void Renderer::CreateDepthBuffer(COORD& pos) noexcept
{
	depthBuffer[POS(pos.X, pos.Y)] = 1;
}
