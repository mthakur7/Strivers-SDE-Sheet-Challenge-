#include <bits/stdc++.h>
vector < int > nsl(vector < int > & heights){
   vector < int > v;
   stack<int>st;
  for(int i=0;i<heights.size();i++){
  if(st.empty())
  v.push_back(-1);
  else{
   while(!st.empty() && heights[st.top()]>=heights[i])
   st.pop();
   if(!st.empty() && heights[st.top()]<heights[i])
   v.push_back(st.top());
   else
   v.push_back(-1);
  }
  st.push(i);
  }
    return v;
 }
    
vector < int > nsr(vector < int > & heights){
    int n=heights.size();
   vector < int > v;
   stack<int>st;
  for(int i=heights.size()-1;i>=0;i--){
  if(st.empty())
  v.push_back(n);
  else{
   while(!st.empty() && heights[st.top()]>=heights[i])
   st.pop();
   if(!st.empty() && heights[st.top()]<heights[i])
   v.push_back(st.top());
   else
   v.push_back(n);
  }
  st.push(i);
  }
    reverse(v.begin(),v.end());
    return v;
 }
   

 int largestRectangle(vector < int > & heights) {
   // Write your code here.
     vector<int>left=nsl(heights);
        vector<int>right=nsr(heights);
        
        int mx=-1;
        for(int i=0;i<heights.size();i++){           
            mx=max(mx,(right[i]-left[i]-1)*heights[i]);
        }
        
      
        return mx;
 }
