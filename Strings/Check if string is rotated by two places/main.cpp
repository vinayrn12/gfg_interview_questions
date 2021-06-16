// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length() == 1 && str2.length() == 1)
            return str1 == str2;
        rotate(str1.begin(), str1.begin()+2, str1.end());
        if(str1 == str2)
            return true;
        rotate(str1.begin(), str1.begin()+str1.size()-4, str1.end());
        if(str1 == str2)
            return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {

	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
