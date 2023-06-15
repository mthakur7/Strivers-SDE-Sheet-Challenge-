int singleNonDuplicate(vector<int>& nums)
{
	// Write your code here
	 int n=nums.size();
        int i=0,j=n-2;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==nums[m^1]){
                i=m+1;
            }
            else
                j=m-1;
            
        }
        return nums[i];
}
