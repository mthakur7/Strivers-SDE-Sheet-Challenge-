
int findMin(int* nums,int n) {
        
       
        int start=0;
        int end =n-1;
        if(n==1)return nums[0];
        while(start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[prev]>nums[mid] && nums[next]>nums[mid])
                return mid;
            else if(nums[end]<nums[mid])
                    start=mid+1;
                else
                    end=mid-1;
            
        }
        return -1;
    }

    int search(int* nums, int n, int target) {
    // Write your code here.
     int idx=findMin(nums,n);
        int i=0,j=idx-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==target)
                return m;
            else  if(nums[m]>target)
                j=m-1;
            else
                i=m+1;
        }
      
            i=idx,j= n-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==target)
                return m;
            else  if(nums[m]>target)
                j=m-1;
            else
                i=m+1;
        }
        return -1;
}
