bool searchMatrix(vector<vector<int>>& matrix, int target) {
          
        int i=0;
        int j=matrix[0].size()-1;
         int f=0;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                f=1;
            break;
            }
            else if((matrix[i][j]>target))
            j--;
            else
            i++;
        } 
        if(f==1)
        return true;
        else
        return false;  
}
