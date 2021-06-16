//Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s{""}, pattern{""};
    getline(cin, s);
    getline(cin, pattern);
    int n = s.length();
    int k = pattern.length();
    int anagram_count = 0, i = 0, j = 0;
    map<char, int> m;
    for(int z=0; z<k; z++){
        if(m.find(pattern[z]) == m.end())
            m[pattern[z]] = 1;
        else
            m[pattern[z]]++;
    }
    int distinct_count = m.size();

    while(j < n){
        if(m.find(s[j]) != m.end()){
            m[s[j]]--;
            if(m[s[j]] == 0)
                distinct_count--;
        }
        if(j-i+1 < k){
            j++;
            continue;
        }
        else if(j-i+1 == k){
            if(distinct_count == 0)
                anagram_count += 1;
            if(m.find(s[i]) != m.end()){
                m[s[i]] += 1; //it went out of our window
                if(m[s[i]] == 1)
                    distinct_count += 1;
            }
            i++;
            j++;
        }
    }

    cout<<anagram_count;
    return 0;
}
