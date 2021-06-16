// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
        /*You are required to complete this method */
    int value(char &ch){
        if(ch == '0')
            return 0;
        else if(ch == '1')
            return 1;
        else if(ch == '2')
            return 2;
        else if(ch == '3')
            return 3;
        else if(ch == '4')
            return 4;
        else if(ch == '5')
            return 5;
        else if(ch == '6')
            return 6;
        else if(ch == '7')
            return 7;
        else if(ch == '8')
            return 8;
        else if(ch == '9')
            return 9;
        else
            return -1;
    }

    int atoi(string str)
    {
        //Your code here
        int res = 0, power = 0;
        for(int i=str.length()-1; i>=0; i--){
            int temp = value(str[i]);
            if(temp == -1 && i>0)
                return -1;
            if(temp == -1 && i==0 && str[i] == '-'){
                res = 0 - res;
                break;
            }
            res = (pow(10, power) * temp) + res;
            power++;
        }
        return res;

    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
