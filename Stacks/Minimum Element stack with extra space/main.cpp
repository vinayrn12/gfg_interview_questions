/*

    Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
    which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1).
    To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

*/

#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"  ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    stack<int> minimum;
    cout<<"\nMenu : \n 1.Push \n 2.Pop \n 3.Minimum \n 4.Display \n 5.Exit"<<endl;
    int ch;
    while(1){
        cin>>ch;
        switch(ch){
            case 1: int val;
                    cout<<"Enter value : ";
                    cin>>val;
                    s.push(val);
                    if(minimum.size() == 0)
                        minimum.push(val);
                    else
                        if(val < minimum.top())
                            minimum.push(val);
                    break;

            case 2: cout<<"Element removed is "<<s.top()<<endl;
                    if(s.top() == minimum.top())
                        minimum.pop();
                    s.pop();
                    break;

            case 3: cout<<"The minimum number is "<<minimum.top()<<endl;
                    break;

            case 4: display(s);
                    break;

            case 5: exit(0);
        }
    }
    return 0;
}

