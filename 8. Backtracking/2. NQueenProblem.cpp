#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	vector<int> temp;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row;
        int y = col;

		// Check for row
        while(y >= 0){
			if(board[x][y] == 1){
				return false;
			}
			y--;
		}

		x = row;
        y = col;

		// Check for upper diagonal
		while(x>=0 && y>=0){
			if(board[x][y] == 1){
				return false;
			}
			x--;
			y--;
		}

		x = row;
        y = col;
		// Check for lower diagonal
		while(x<n && y>=0){
			if(board[x][y] == 1){
				return false;
			}
			x++;
			y--;
		}

		return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	// Base Case
	if(col == n){
		addSolution(board, ans, n);
		return ;
	}

	// Solve 1 case 
	for(int row=0; row<n; row++){
		if(isSafe(row, col , board, n)){
			// If placing Queens is Safe
			board[row][col]=1;
			solve(col+1, board, ans, n);
			board[row][col]=0;
		}
	}

}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n , vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0, board, ans, n);

	return ans;
}


// optimised Solution
bool isSafe2(int n, int row, int col, unordered_map<int, bool> &rowCheck, 
            unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal) {
    // Check if the current row, or either diagonal is already under attack
    if (rowCheck[row] || upperDiagonal[row + col] || lowerDiagonal[n - 1 + col - row]) {
        return false;
    }
    return true;
}

void solve2(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n,
           unordered_map<int, bool> &rowCheck, unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal) {
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe2(n, row, col, rowCheck, upperDiagonal, lowerDiagonal)) {
            board[row][col] = 1;
            rowCheck[row] = true;
            upperDiagonal[row + col] = true;
            lowerDiagonal[n - 1 + col - row] = true;

            solve2(col + 1, board, ans, n, rowCheck, upperDiagonal, lowerDiagonal);

            // Backtrack
            board[row][col] = 0;
            rowCheck[row] = false;
            upperDiagonal[row + col] = false;
            lowerDiagonal[n - 1 + col - row] = false;
        }
    }
}

vector<vector<int>> nQueens2(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiagonal;
    unordered_map<int, bool> lowerDiagonal;

    solve2(0, board, ans, n, rowCheck, upperDiagonal, lowerDiagonal);

    return ans;
}

int main(){
    // vector<vector<int>> ans = nQueens(4);
    vector<vector<int>> ans = nQueens2(4);


    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}