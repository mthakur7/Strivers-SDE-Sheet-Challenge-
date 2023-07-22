/*
    Time complexity: O(log(K))
    Space complexity: O(log(K))

    where K denotes the Kth person in line waiting to be served.
 */


int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) 
{     
    // If length of first array is smaller then length of second then swap both the arrays.    
    if (m > n) 
    {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
  
    if (m == 0) 
    {
        return row2[k - 1];
    }
    
    // If k is equal to 1
    if (k == 1) 
    {
        return min(row1[0], row2[0]);
    }
  
    int i = min(m, k / 2);
    int j = min(n, k / 2);
    
    // If row1[i - 1] is greater than row2[j - 1]
    if (row1[i - 1] > row2[j - 1]) 
    {
        vector<int> newRow2;
        newRow2.assign(row2.begin() + j, row2.end());
        
        return ninjaAndLadoos(row1, newRow2, m, n - j, k - j);
    } 

    vector<int> newRow1;
    newRow1.assign(row1.begin() + i, row1.end());
        
    return ninjaAndLadoos(newRow1, row2, m - i, n, k - i);  
} 
