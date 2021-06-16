// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
    return minEle;
   //Your code here
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
    int top;
    if(s.empty())
        return -1;
    if(s.top() >= minEle){
        top = s.top();
        s.pop();
    }
    else{
        top = minEle;
        minEle = (2 * minEle) - s.top();
        s.pop();
    }
	return top;
}

/*push element x into the stack*/
void _stack::push(int a)
{
   //Your code here
   if(s.empty()){
	    minEle = a;
	    s.push(a);
	}
	else{
	    if(a >= minEle)
	        s.push(a);
	    else{
	        s.push((2 * a) - minEle);
	        minEle = a;
	    }
	}
}
