#include <stack>
#include "solveNQueens.h"
#include "board.h"

bool solve(Board &board, int N)
{
	int numPrePlacedQueens = board.getQueens().size();

	int startY = board.firstEmptyRow();

	if(startY >N){ //if all rows are filled, check to see if solution already given.
		return board.getQueens().size() == N;
	}

	//stack to track search states
	std::stack<state> funcStack;

	funcStack.push(state(1,startY,numPrePlacedQueens));

	//begin search tree using stack
	while(!funcStack.empty()){
		state currState = funcStack.top();
		funcStack.pop();

		int x = currState.x;
		int y = currState.y;
		int expectedQueens = currState.numQueens;

		//restore the board to the expected state
		while(board.getQueens().size() > expectedQueens){
			board.removeQueen();
		}

		if (y > N){ //if we are past the last row we found a solution!
			if (board.getQueens().size() == N){
				return true;
			}
			continue; //added for safety in case there are logical errors for now
		}

		//if we are not at the first column, we are dealing with a backtrack state. Remove queen in current row first (queen from failed state)
		if (x > 1 && board.getQueens().size() >numPrePlacedQueens){
			if(!board.getQueens().empty() && board.getQueens().back().second == y){
				board.removeQueen();
			}
		}

		//now, we try placing queens in the current column, starting at col x
		bool placed = false;

		for (int currx = x; currx <= N; currx++){
			if (board.canPlace(currx, y)){
				//place a queen at (currx,y)
				board.placeQueen(currx, y);

				int currentQueens = board.getQueens().size();

				//push the backtrack state --> if this path fails, try the next col
				if(currx + 1 <= N){
					funcStack.push(state(currx+1, y, currentQueens - 1));
				}

				//push the next state by moving to the next empty row and cotinuing
				int nextY = board.firstEmptyRow();
				funcStack.push(state(1, nextY, currentQueens));

				placed = true;
				break;
			}
		}
	}

	return false;
}
