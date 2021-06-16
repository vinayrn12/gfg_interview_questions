#include <bits/stdc++.h>

using namespace std;

void Insert(stack<int> &s, int &ele){
    if(s.empty() || s.top() <= ele){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    Insert(s, ele);
    s.push(temp);
}

void Sort(stack<int> &s){
    if(s.size() == 1)
        return;
    int ele = s.top();
    s.pop();
    Sort(s);
    Insert(s, ele);
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
    Sort(s);
    while(! s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
