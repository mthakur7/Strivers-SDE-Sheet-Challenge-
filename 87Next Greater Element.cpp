#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
       vector<int>v;
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty())
                v.push_back(-1);             
                      
                else{
                    while(!st.empty() && st.top()<=arr[i])
                        st.pop();
                    if(!st.empty())
                     v.push_back(st.top());
                   else
                       v.push_back(-1); 
                }
            st.push(arr[i]);
            }
        reverse(v.begin(),v.end());
       
        return v;

}
