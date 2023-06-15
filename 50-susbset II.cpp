/*
    Time Complexity: O(2^N)
    Space Complexity: O(2^N)

    where ‘N’ is the number of elements in ‘ARR’.    
*/

#include<algorithm> 
void rec(int st,vector<int> &cur, vector<int> &arr, vector<vector<int>> &subsets){

    subsets.push_back(cur);

    for(int i = st; i < arr.size(); i++){
        
        if (i==st or arr[i] != arr[i-1]){

            cur.push_back(arr[i]);
            rec(i+1, cur, arr, subsets);
            cur.pop_back();
        }
    }

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());
    vector<int> cur;
    rec(0, cur, arr, subsets);

    return subsets;
}
