#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
	priority_queue<int>pq;
	for(int i=0;i<arr.size();i++)
	pq.push(arr[i]);
	for(int i=0;i<k-1;i++){
		pq.pop();
	}
	return pq.top();
}
