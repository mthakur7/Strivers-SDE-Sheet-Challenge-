#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int tp;
    int sz;
    int*arr;
    
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        tp=-1;
        sz=capacity;
    }

    void push(int num) {
        // Write your code here.
        if (tp<sz-1) {
          tp++;
          arr[tp] = num;
          
        }
    }

    int pop() {
        // Write your code here.
        if(tp==-1)
        return -1;
        else{
            int x=arr[tp];
            tp--;            
            return x;
        }
    }
    
    int top() {
        // Write your code here.
        if(tp==-1)
        return -1;
        else {
          int x = arr[tp];
          return x;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(tp==-1)
        return 1;
        else
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(tp==sz-1)
        return 1;
        else
        return 0;
    }
    
};
