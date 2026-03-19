#ifndef SOLVE_H
#define SOLVE_H

#include "board.h"

struct state{
	int x;
	int y;
	int numQueens;

	state(int xval, int yval, int nq): x(xval), y(yval), numQueens(nq){}
};

bool solve(Board&, int);

#endif