/*
Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai).
N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0).
Find two lines, which together with x-axis forms a container, such that it contains the most water.
*/

// { Driver Code Starts
//Initial template for C++

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long max_area = 0, area;
    int i=0, j=len-1;
    while(i < j){
        if(A[i] > A[j]){
            area = A[j] * (j - i);
            max_area = max(max_area, area);
            j--;
        }
        else{
            area = A[i] * (j - i);
            max_area = max(max_area, area);
            i++;
        }
    }
    return max_area;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
