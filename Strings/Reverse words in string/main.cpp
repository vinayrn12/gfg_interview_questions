//Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    string reverseWords(string S)
    {
        // code here
        string s{""};
        vector<string> words;
        for(int i=0; i<S.length(); i++){
            if(S[i] == '.'){
                words.push_back(s);
                s = "";
            }
            else
                s += S[i];
        }
        words.push_back(s);
        reverse(words.begin(), words.end());
        s = "";
        int i;
        for(i=0; i<words.size()-1; i++)
            s += words[i] + '.';
        s += words[i];
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
