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

    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here

        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pair<int, int> src;
        src.first = 0;
        src.second = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        dist[0][0] = grid[0][0];
        q.push(make_pair(dist[0][0], make_pair(src.first, src.second)));

        while(! q.empty()){
            pair<int, pair<int, int>> curr = q.top();
            q.pop();


            for(int i=0; i<4; i++){
                int row = curr.second.first + row_pos[i];
                int col = curr.second.second + col_pos[i];
                if(isvalid(row, col, n)){
                    if(dist[row][col] > dist[curr.second.first][curr.second.second] + grid[row][col]){
                        dist[row][col] = dist[curr.second.first][curr.second.second] + grid[row][col];
                        q.push(make_pair(dist[row][col], make_pair(row, col)));
                    }
                }
            }

        }

        return dist[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
