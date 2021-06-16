//Given a string s, find the length of the longest substring without repeating characters.


#include <bits/stdc++.h>

using namespace std;

int longest_substr(string s){
    int i=0, j=0, longest=-1;
    map<char, int> m;
    while(j < s.length()){
        m[s[j]]++;
        if(j-i+1 < m.size())
            j++;
        else if(m.size() == j-i+1){
            longest = max(longest, j-i+1);
            j++;
        }
        else{
            while(m.size() < j-i+1){
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return longest;
}

int main()
{
    string s;
    getline(cin, s);
    cout<<longest_substr(s);
    return 0;
}
