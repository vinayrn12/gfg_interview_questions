// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int row_pos[4] = {-1, 0, 1, 0};
    int col_pos[4] = {0, -1, 0, 1};

    bool isvalid(int &row, int &col, int &n){
        return (row >= 0) && (row < n) && (col >= 0) && (col < n);
    }

    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> src, dest;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    src.first = i;
                    src.second = j;
                }
                if(grid[i][j] == 2){
                    dest.first = i;
                    dest.second = j;
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.emplace(src.first, src.second);
        visited[src.first][src.second] = true;

        while(! q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            if(curr.first==dest.first && curr.second==dest.second)
                return true;

            for(int i=0; i<4; i++){
                int row = curr.first + row_pos[i];
                int col = curr.second + col_pos[i];

                if(isvalid(row, col, n) && grid[row][col]!=0 && !visited[row][col]){
                    visited[row][col] = true;
                    q.emplace(row, col);
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
