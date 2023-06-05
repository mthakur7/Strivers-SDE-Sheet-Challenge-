#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    public:
    queue<int>q1;
    queue<int>q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        int x=q1.size();
        return x;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.empty())
        return 1;
        else
        return 0;
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function.

         if(q1.empty())
          return -1;
         else {
           int ans=q1.back();
           int x = q1.size()-1;          

            while(x--){
                int f=q1.front();
                q1.pop();
                q2.push(f);
            }
            q1.pop();
             while(!q2.empty()){
                  int f=q2.front();
                  q2.pop();
                q1.push(f);
            }


           return ans;
         }
    }

    int top() {
        // Implement the top() function.
        if(q1.empty())
        return -1;
        else
        return q1.back();
       
    }
};
