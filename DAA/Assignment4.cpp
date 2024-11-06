//Design n-Queens matrix having first Queen placed. Use backtracking to place 
//remaining Queens to generate the final n-queen 
#include <bits/stdc++.h>
using namespace std;
void printBoard(vector<vector<int>> & board){
	int n = board.size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<(board[i][j]==1?"Q ":". ");
		}
		cout<<endl;
	}
	return;
}
bool isSafe(vector<vector<int>>& board, int row, int col, int n){
	// check this column on upper rows
	for(int i =0;i<row;i++){
		if(board[i][col] == 1){
			return false;
		}
	}
	 // Check upper left diagonal
	 for(int i = row,j =col; i>=0 && j>=0 ; i--, j--){
	 	if(board[i][j]==1){
	 		return false;
		 }
	 }
	 // Check upper right diagonal
	 for(int i = row, j = col; i>=0 && j<n ; j++ , i--){
	 	if(board[i][j]==1){
	 		return false;
		 }
	 }
	 return true;
}
bool solveNQueens(vector<vector<int>> & board, int i,int n){
	if (i >= n) // All queens are placed
        return true;
    for(int col = 0;col<n;col++)
	{
		if(isSafe(board,i,col,n)){
			board[i][col] = 1;
			
			if(solveNQueens(board,i+1,n)){
				return true;
			}
			
			board[i][col] = 0;
		}
		
	}    
	return false;
}
int main(){
	int n;
	cout<<"Enter the value in N: ";
	cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
	int x,y;
	cout<<"Place the First Queen (ex: 0 1) :";
	cin>>x>>y;
	if(x>=n || x<0 || y>=n || y<0){
		cout<<"Invalid position for the first queen. Exiting." << endl;
		return 1;
	}
	board[x][y] = 1;
	if(solveNQueens(board,x+1,n)){
		cout<<"Solution: "<<endl;
		printBoard(board);
	}	
	else{
		cout << "\nNo solution exists for the given initial position of the first queen.\n";
	}
	return 0;
}








