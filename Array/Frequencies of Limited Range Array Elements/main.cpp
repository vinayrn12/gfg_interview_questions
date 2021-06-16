/*
Given an array A[] of n positive integers which can contain integers from 1 to P where elements can be repeated
or can be absent from the array. Your task is to count the frequency of all elements from 1 to n.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void frequencycount(vector<int>& arr,int n);

 // } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencycount(vector<int>& arr,int n)
    {
        // code here
        for(int i=0; i<n; i++)
            arr[i] -= 1;

        for(int i=0; i<n; i++)
            arr[arr[i]%n] = arr[arr[i]%n] + n;
        for(int i=0; i<n; i++)
            arr[i] /= n;
    }
};


// { Driver Code Starts.

int main()
{
	long long t;

	//testcases
	cin >> t;

	while(t--){

	    int n;
	    //size of array
	    cin >> n;

	    vector<int> arr(n,0);

	    //adding elements to the vector
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }

        Solution ob;
        //calling frequncycount() function
		ob.frequencycount(arr,n);

		//printing array elements
	    for (int i =0; i<n; i++)
			cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}




  // } Driver Code Ends
