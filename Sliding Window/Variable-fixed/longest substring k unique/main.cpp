//Given a string you need to print the size of the longest possible substring that has exactly K unique characters and repeating characters.
//If there is no possible substring then print -1.

#include <bits/stdc++.h>

using namespace std;

int longest_substr(string s, int k){
    int i=0, j=0, longest=-1;
    map<char, int> m;
    while(j < s.length()){
        m[s[j]]++;
        if(m.size() < k)
            j++;
        else if(m.size() == k){
            longest = max(longest, j-i+1);
            j++;
        }
        else{
            while(m.size() > k){
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
    int k;
    cin>>k;
    cout<<longest_substr(s, k);
    return 0;
}
