#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
        
            int ct1=0,ct2=0,el1=0,el2=0;
        for(int i=0;i<nums.size();i++){
            if(ct1==0 && nums[i]!=el2){
           el1=nums[i];
            ct1=1;
        }
          else if(ct2==0 && nums[i]!=el1){
          el2=nums[i];
            ct2=1;
        }
        else if(nums[i]==el1)
                ct1++;
        else if(nums[i]==el2)
                ct2++;
         else{
             ct1--; ct2--;
         }        
            
            
        }
       vector<int> ls;

 
    ct1 = 0, ct2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == el1) ct1++;
        if (nums[i] == el2) ct2++;
    }

    int mini = int(nums.size() / 3) + 1;
        if(el1!=el2){
    if (ct1 >= mini) ls.push_back(el1);
    if (ct2 >= mini) ls.push_back(el2);

        }else if(el1==el2)
             if (ct1 >= mini) ls.push_back(el1);
            
        
    return ls;

}
