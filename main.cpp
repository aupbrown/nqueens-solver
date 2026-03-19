//this file will deal with the main flow and execution of the program. As well as file I/O and calling functions from other files.

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "board.h"
#include "solveNQueens.h"

using namespace std;

int main(int argc, char* argv[]){
	if (argc != 3){
		cerr << "Usage: " << argv[0] << "<input_file> <output_file>";
		return 1;
	}

	ifstream inFile(argv[1]);

	if(!inFile.is_open()){
		cerr <<"Error: Could not open input file for reading." << endl;
		return 1;
	}

	vector<vector<int>> allLines;
	string line;
	while(getline(inFile, line)){
		istringstream iss(line);
		int num;
		vector<int> oneLine;
		while (iss >> num){
			oneLine.push_back(num);
		}
		allLines.push_back(oneLine);
	}
	inFile.close();

	//opening outfile to prepare for output
	ofstream outFile(argv[2]);
	if(!outFile.is_open()){
			cerr << "Could not open output file for writing.";
			return 1;
		}

	for (size_t i = 0; i < allLines.size(); i++){ //iterate through each line of input, create board, solve, and output result
		//grabbing current line of input
		const vector<int>& currLine = allLines[i];

		//initializing board
		int N = currLine[0];
		Board chess_board(N);

		bool validInput = true;

		int nTracker = 0;
		//placing queens from input on to board
		for (size_t i = 1; i + 1 < currLine.size(); i+=2){
			if(!chess_board.canPlace(currLine[i], currLine[i+1])){
				validInput = false;
				break;
			}
			chess_board.placeQueen(currLine[i], currLine[i+1]);
			nTracker++;
		}

		if (!validInput){ //given input is not possible already
			outFile << "No solution\n";
			continue;
		}

		if(nTracker > N){ // >N queens placed already. Invalid input
			outFile << "No solution\n";
			continue;
		}

		if(nTracker == N){ //given input is already a solution
			for (size_t i =0; i < chess_board.getQueens().size(); i++){
				outFile << chess_board.getQueens()[i].first << " " << chess_board.getQueens()[i].second << " ";
			}
			outFile <<"\n";
			continue;
		}

		//solving board
		bool solution = solve(chess_board, N);

		if (!solution){ //if no solution, output "No solution"
			outFile << "No solution\n";
			continue;
		}

		//sort solution in increasing column order
		chess_board.sortColumns();

		//iterate through solution vector and output queens to outFile
		for (size_t i =0; i < chess_board.getQueens().size(); i++){
			outFile << chess_board.getQueens()[i].first << " " << chess_board.getQueens()[i].second << " ";
		}
		outFile << "\n";
	}

	outFile.close();
	return 0;
}