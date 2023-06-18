#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
	// Write your code here.
	  int ct=0,el=-1;
        for(int i=0;i<n;i++){
            if(ct==0){
                el=nums[i];
            ct=1;
        }
            else if(nums[i]==el)
                ct++;
            else if(nums[i]!=el)
                ct--;
            
        }
		ct=0;
		for(int i=0;i<n;i++){
			if(nums[i]==el)
			ct++;
		}
		if(ct>n/2)return el;
		else return -1;
     
}
