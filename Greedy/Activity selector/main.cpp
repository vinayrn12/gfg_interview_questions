// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> activities(n);
        for(int i=0; i<n; i++)
            activities[i] = make_pair(start[i], end[i]);
        sort(activities.begin(), activities.end(), comp);

        int i=0, count=1;
        for(int j=1; j<n; j++){
            if(activities[j].first > activities[i].second){
                count ++;
                i = j;
            }
        }

        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;

    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
