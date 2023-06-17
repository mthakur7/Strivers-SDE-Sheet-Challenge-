#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
    int l=0;
   int m=0;
   int h=n-1;

        while(m<=h){
            if(nums[m]==0){
               swap(nums[l],nums[m]);
               l++;
               m++;
            }
            else if(nums[m]==1)
            m++;
            else if(nums[m]==2){
                swap(nums[m],nums[h]);               
                h--;
            }
        }

}
