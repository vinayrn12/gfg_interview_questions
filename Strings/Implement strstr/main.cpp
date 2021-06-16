// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;

        cin>>a;
        cin>>b;

        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends





//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int i=0, c;
    if(x.length() > s.length())
        return -1;
    while(i < s.length()){
        if(s[i] == x[0]){
            c = 0;
            for(int k=0; k<x.length(); k++){
                if(s[i] == x[k]){
                    c++;
                    i++;
                }
            }
            if(c == x.length())
                return i-c;
            else
                i = i - c + 1;
        }
        else
            i++;
    }
    return -1;
}
