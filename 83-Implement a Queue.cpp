#include <bits/stdc++.h> 
class Queue {
    int*arr;
    int f,r,s;
public:
 Queue() {
        // Implement the Constructor
        arr=new int[5001];
        f=-1;
        r=-1;
        s=0;
    }
    Queue(int c) {
        // Implement the Constructor
        arr=new int[c];
        f=-1;
        r=-1;
        s=0;
    }
  

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(s==0)
        return 1;
        else
        return 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(r==-1){
            r=0;
            f=0;
        }
        else
        r++;        
        arr[r]=data;
        s++;
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(s==0)
        return -1;
        else{
            int ans=arr[f];
            f++; 
            s--;           
            return ans;
            
        }
    }

    int front() {
        // Implement the front() function
        if(s==0)
        return -1;
        else
        return arr[f];
    }
};
