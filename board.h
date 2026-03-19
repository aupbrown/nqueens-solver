#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>

class Board{
	private:
		int N;
		std::vector<std::pair<int,int>> queens;

	public:
		Board(int);
		
		bool canPlace(int,int) const;
		void placeQueen(int,int);
		void removeQueen();
		int firstEmptyRow() const;
		void sortColumns();

		const std::vector<std::pair<int,int>>& getQueens() const;
};

#endif