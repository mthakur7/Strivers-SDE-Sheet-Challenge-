#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
      vector<int>dp;
      int ans=1;
      dp.push_back(arr[0]);
      for (int i=1;i<n;i++)
      {
          if (arr[i]>dp.back())
          {
              dp.push_back(arr[i]);
          }
          else{
              int ind=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
              dp[ind]=arr[i];
          }
      }
      return dp.size();
}
