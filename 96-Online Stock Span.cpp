#include <bits/stdc++.h>
vector < int > ngl(vector < int > &arr){
   vector < int > v;
   stack<int>st;
  for(int i=0;i<arr.size();i++){
  if(st.empty())
  v.push_back(-1);
  else{
   while(!st.empty() && arr[st.top()]<=arr[i])
   st.pop();
   if(!st.empty() && arr[st.top()]>arr[i])
   v.push_back(st.top());
   else
   v.push_back(-1);
  }
  st.push(i);
  }
    return v;
 }

    
   vector<int> findSpans(vector<int> &price) {  
        vector<int>v=ngl(price);
        for(int i=0;i<price.size();i++){
            if(v[i]==-1)v[i]=i+1;
            else{
                v[i]=i-v[i];
            }
        }
       return v;
    }
