#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
      int mx=0;
    int mn=prices[0];
    for(int i=1;i<prices.size();i++){      
            mx=max(mx,prices[i]-mn);
            mn=min(mn,prices[i]);        
    }
    return mx;
}
