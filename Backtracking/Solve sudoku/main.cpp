// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find a solved Sudoku.
    bool findunassignedlocation(int grid[N][N], int &row, int &col){
        for(row=0; row<N; row++)
            for(col=0; col<N; col++)
                if(grid[row][col] == UNASSIGNED)
                    return true;
        return false;
    }

    bool usedinrow(int grid[N][N], int row, int num){
        for(int col=0; col<N; col++)
            if(grid[row][col] == num)
                return true;

        return false;
    }

    bool usedincol(int grid[N][N], int col, int num){
        for(int row=0; row<N; row++)
            if(grid[row][col] == num)
                return true;

        return false;
    }

    bool usedingrid(int grid[N][N], int row_start, int col_start, int num){
        for(int row=0; row<3; row++)
            for(int col=0; col<3; col++)
                if(grid[row+row_start][col+col_start] == num)
                    return true;

        return false;
    }

    bool issafe(int grid[N][N], int row, int col, int num){
        return !usedinrow(grid, row, num) && !usedincol(grid, col, num)
               && !usedingrid(grid, row-row%3, col-col%3, num) && grid[row][col] == UNASSIGNED;
    }

    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        int row, col;

        if(! findunassignedlocation(grid, row, col))
            return true;

        for(int num=1; num<=9; num++){
            if(issafe(grid, row, col, num)){
                grid[row][col] = num;

                if(SolveSudoku(grid))
                    return true;

                grid[row][col] = UNASSIGNED;
            }
        }

        return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N])
    {
        // Your code here
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];

		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];

		Solution ob;

		if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout<<endl;
	}

	return 0;
}  // } Driver Code Ends
