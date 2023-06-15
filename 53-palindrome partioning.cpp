#include <bits/stdc++.h> 
    bool isPal(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    void fun(int idx, string s,vector<string>ds, vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
       for(int i=idx;i<s.size();i++){
           string st=s.substr(idx,i-idx+1);
           if(isPal(st)){
               ds.push_back(st);
               fun(i+1,s,ds,ans);
                ds.pop_back();
               
           }
           
       } 
        
    }

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
        vector<vector<string>>ans;
        vector<string>ds;
        fun(0,s,ds,ans);
        return ans;
}
