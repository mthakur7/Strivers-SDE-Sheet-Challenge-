#include <bits/stdc++.h> 

  bool isVal(string x, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(x==wordDict[i])
                return true;
        }
        return false;
    }
    void func(int idx, string s,vector<string>& wordDict,vector<string>&ans,string y){
        if(idx==s.length()){
            ans.push_back(y);
            return;
        }
       // if(memo[idx]!=-1)return memo[idx];
        for(int i=idx;i<s.length();i++){
            string x=s.substr(idx,i-idx+1); 
             //string y=s.substr(i-idx+1);
            if(isVal(x,wordDict)){
                string k="";
                if(y!="")
                    k=y+" "+x;
               else
                   k=x;
               func(i+1,s,wordDict,ans,k)   ;     
                    
                  
            }    
            }
          
            
        
      
    }

  vector<string> wordBreak(string &s, vector<string> &wordDict)
{
    // Write your code here
     vector<int>memo(s.length()+1,-1);
          vector<string>ans;
          func(0,s,wordDict,ans,"");
        return ans;

}  
