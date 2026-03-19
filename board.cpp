#include "board.h"

#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

Board::Board(int n) : N(n)
{
}

bool Board:: canPlace(int x, int y) const{
	for (int i = 0; i < queens.size(); i++){
		auto currPair = queens[i];
		int currx = currPair.first;
		int curry = currPair.second;

		//check same column
		if (x == currx){
			return false;
		}

		//check same row
		if (y == curry){
			return false;
		}

		//check same diaganol
		if(abs(currx - x) == abs(curry - y)){
			return false;
		}
	}

	return true;
}

void Board:: placeQueen(int x, int y){
	queens.push_back({x,y});
}

void Board:: removeQueen(){
	if(!queens.empty()){
		queens.pop_back();
	}
}

//Output: if all rows occupied: returns N+1
int Board::firstEmptyRow() const{
	vector<bool> rowsOccupied(N+1, false);
	for (const auto& queen : queens){
		rowsOccupied[queen.second] = true;
	}

	for (int i = 1; i <= N; i++){
		if (!rowsOccupied[i]){
			return i;
		}
	}

	//if all rows occupied: return N+1
	return N + 1;
}

void Board::sortColumns(){
	std::sort(queens.begin(), queens.end());
	return;
}


const vector<pair<int,int>>& Board::getQueens() const{
	return queens;
}