#include <bits/stdc++.h>

using namespace std;

void Insert(stack<int> &s, int &ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    Insert(s, ele);
    s.push(temp);
}

void Reverse(stack<int> &s){
    if(s.size() == 0)
        return;
    int ele = s.top();
    s.pop();
    Reverse(s);
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
    cout<<"Original stack: "<<endl;
    stack<int> s1;
    s1 = s;
    while(! s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    Reverse(s);
    cout<<"Reversed stack : "<<endl;
    while(! s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
