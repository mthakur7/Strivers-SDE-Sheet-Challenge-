#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int count=0;
    int deno[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    for(int i=n-1;i>=0;i--){
      
        while(amount>=deno[i]){
            amount-=deno[i];
            count++;
             if(amount==0)
        break;
        }
       
    }
    return count;
}
