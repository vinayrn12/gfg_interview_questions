/*

    Given two strings s and t, return the minimum window in s which will contain all the characters in t.
    If there is no such window in s that covers all characters in t, return the empty string "".

*/

//for now we return the size of the window

#include <bits/stdc++.h>

using namespace std;

string mws(string s, map<char, int> &m){
    int i=0, j=0, c=m.size(), min_window = INT_MAX;
    string ans;
    while(j < s.length()){
        if(m.find(s[j]) != m.end()){
            m[s[j]]--;
            if(m[s[j]] == 0)
                c--;
        }
        if(c == 0){
            while(c == 0){
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(m[s[i]] == 1)
                        c++;
                }
                if(min_window > j-i+1){
                    min_window = j-i+1;
                    ans = s.substr(i, min_window);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map<char, int> m;
    for(int i=0; i<t.length(); i++)
        m[t[i]]++;
    cout<<mws(s, m);
    return 0;
}
