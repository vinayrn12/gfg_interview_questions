/*

    John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.

*/

#include <bits/stdc++.h>

using namespace std;

int get_toys(string s){
    int i=0, j=0, max_toys=0;
    map<char, int> m;
    while(j < s.length()){
        m[s[j]]++;
        if(m.size() < 2)
            j++;
        else if(m.size() == 2){
            max_toys = max(max_toys, j-i+1);
            j++;
        }
        else{
            while(m.size() > 2){
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return max_toys;
}

int main()
{
    string s;
    getline(cin, s);
    cout<<get_toys(s);
    return 0;
}
