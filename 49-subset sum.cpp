#include <bits/stdc++.h> 
vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here.
    int N=arr.size();
       vector<int>ans;
        for(int i=0;i<pow(2,N);i++){
         int s=0;
            int x=i,j=N-1;
            while(x!=0){
                int r=x%2;
                s+=r*arr[j--];
                x=x/2;
            }
              ans.push_back(s);
           
        }
        sort(ans.begin(),ans.end());
         return ans;
}
