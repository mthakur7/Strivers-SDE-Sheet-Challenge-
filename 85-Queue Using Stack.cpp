#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int>s1;
    stack<int>s2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
           while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
          while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
          if(!s1.empty()){
        int x=s1.top();
        s1.pop();
        return x;
        }else
            return -1;
    }

    int peek() {
        // Implement the peek() function here.
           if(!s1.empty())
        return s1.top();
        else
            return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};
