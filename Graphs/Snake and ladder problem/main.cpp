// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        int move[30];
        for(int i=0; i<30; i++)
            move[i] = -1;

        for(int i=0; i<2*N; i+=2)
            move[arr[i]-1] = arr[i+1]-1;

        vector<bool> visited(30, false);

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;
        int res;

        while(! q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            int v = curr.second;

            if(v == 29){
                res = curr.first;
                break;
            }

            for(int j=(v+1); j<=(v+6) && j<30; j++){
                if(! visited[j]){
                    pair<int, int> temp;
                    temp.first = curr.first+1;
                    visited[j] = true;

                    if(move[j] != -1)
                        temp.second = move[j];
                    else
                        temp.second = j;
                    q.push(temp);
                }
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
