// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    // Code here
	    vector<pair<int, int>> nums_pos(nums.size());
	    for(int i=0; i<nums.size(); i++){
	        nums_pos[i].first = nums[i];
	        nums_pos[i].second = i;
	    }

	    sort(nums_pos.begin(), nums_pos.end());

	    vector<bool> visited(nums.size(), false);
	    int res = 0;

	    for(int i=0; i<nums.size(); i++){
	        if(visited[i] || nums_pos[i].second == i)
	            continue;

	        int cycle = 0;
	        int j = i;
	        while(! visited[j]){
	            cycle ++;
	            visited[j] = true;
	            j = nums_pos[j].second;
	        }

	        if(cycle > 0)
	            res += (cycle - 1);
	    }

	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
