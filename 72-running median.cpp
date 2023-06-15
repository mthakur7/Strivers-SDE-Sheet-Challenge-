#include <bits/stdc++.h>
    void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0;i<n;i++){
     int num=arr[i];
       maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size())
         cout<< maxHeap.top()<<" ";
        else
        cout<< (maxHeap.top() + minHeap.top()) / 2<<" ";
    }
      
}
