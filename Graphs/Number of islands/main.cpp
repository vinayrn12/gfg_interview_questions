// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    //ROW and COL arrays hold adjacent positions for every cell to check connectivity
    int ROW[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int COL[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool isSafe(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        int rows = grid.size();
        int cols = grid[0].size();

        return (row >= 0) && (row < rows) && (col >= 0) && (col < cols) && (! visited[row][col]) && (grid[row][col] == '1');
    }

    void dfsutil(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        visited[row][col] = true;

        for(int k=0; k<8; k++)
            if(isSafe(row+ROW[k], col+COL[k], grid, visited))
                dfsutil(row+ROW[k], col+COL[k], grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int count = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(! visited[i][j] && grid[i][j] == '1'){
                    dfsutil(i, j, grid, visited);

                    count ++;
                }
            }
        }

        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
