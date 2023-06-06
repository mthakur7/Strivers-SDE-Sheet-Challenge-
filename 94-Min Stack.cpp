#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	public:
	 stack<int>st;
    stack<int>st2;
   
    minStack(){

	}
    void push(int val) {
       if(st2.empty() || val<=st2.top()){
           st.push(val);
           st2.push(val);
       }
        else{
       
          st.push(val);
        }
    }
    
    int pop() {
		if(st.size()==0) return -1;
        int x=st.top();
        int y=st2.top();
        if(x==y){
            st.pop();
            st2.pop();
			
        }
        else
            st.pop();
       return x; 
    }
    
    int top() {
		if(st.size()==0) return -1;
        return st.top();
    }
    
    int getMin() {
		if(st2.size()==0) return -1;
      return st2.top();  
    }
		
	
};
