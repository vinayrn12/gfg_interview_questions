// An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> res;
        res.push_back(a[n-1]);
//        int left = n-2, right=n-1;
//        while(left >= 0){
//            if(a[left] >= a[right]){
//                res.push_back(a[left]);
//                right = left;
//                left--;
//            }
//            else
//                left--;
//        }
        int leader = n-1;
        for(int j=n-2; j>=0; j--){
            if(a[j] >= a[leader]){
                leader = j;
                res.push_back(a[leader]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array

        int a[n];

        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);

        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }

        cout << endl;

   }
}
  // } Driver Code Ends
