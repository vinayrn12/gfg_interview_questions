//Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all the elements of A except A[i].

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);

        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }

        vec = productExceptSelf(arr,n);   // function call

        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {

    //code here
    vector<long long int> product(n);
    if(n == 1){
        product[0] = 1;
        return product;
    }
    long long int temp = 1;
    for(int i=0; i<n; i++){
        product[i] = temp;
        temp *= nums[i];
    }
    temp = 1;
    for(int i=n-1; i>=0; i--){
        product[i] *= temp;
        temp *= nums[i];
    }
    return product;
}
