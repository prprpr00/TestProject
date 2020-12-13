#pragma once
#include"stdafx.h"
COORD& BallPostion(COORD& pos, COORD& v);

int main() {
	Renderer rd;
	UTimer uTimer;
	COORD position1 = { 10, 5 };
	COORD velocity1 = { -1, -1 };
	COORD position2 = { 50, 20 };
	COORD velocity2 = { -1, 1 };
	COORD position3 = { 70, 30 };
	COORD velocity3 = { 1,1 };

	for (;;) {
		if (uTimer.IsPeek()) {
			rd.CreateDepthBuffer(BallPostion(position2, velocity2));
			rd.CreateDepthBuffer(BallPostion(position1, velocity1));
			rd.CreateDepthBuffer(BallPostion(position3, velocity3));

			rd.Rasterization();
			rd.Draw();
		}
	}
}

COORD& BallPostion(COORD& pos, COORD& v) {
	if (pos.X + v.X < 0 || pos.X + v.X > 128) {
		v.X = -v.X;
	}
	if (pos.Y + v.Y < 0 || pos.Y + v.Y > 47) {
		v.Y = -v.Y;
	}
	pos.X += v.X;
	pos.Y += v.Y;
	return pos;
}