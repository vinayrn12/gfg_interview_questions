#include <bits/stdc++.h>

using namespace std;

void Sort(stack<int> &s, int k){
    if(s.size() == 1)
        return;
    if(k == 1){
        s.pop();
        return;
    }
    int ele = s.top();
    s.pop();
    Sort(s, k-1);
    s.push(ele);
}

int main()
{
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        s.push(temp);
    }
    Sort(s, (n/2)+1);
    while(! s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
