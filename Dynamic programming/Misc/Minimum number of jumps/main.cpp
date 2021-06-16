/*
    Given an array of integers where each element represents the max number of steps that can be made forward from that element.
    Find the minimum number of jumps to reach the end of the array (starting from the first element).
    If an element is 0, then you cannot move through that element.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    int count = 0, curr_pos = 0, max_possible = 0;
    for(int i=0; i<n; i++){

        max_possible = max(max_possible, i + arr[i]);

        if(i == max_possible)
            return -1;

        if(max_possible >= n-1)
            return 1 + count;

        if(i == curr_pos){
            count += 1;
            curr_pos = max_possible;
        }
    }
    return count;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
