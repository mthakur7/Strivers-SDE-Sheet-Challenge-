/*
    Time Complexity : O(N * log(K))
    Space Complexity : O(N)

    Where 'N' is the maximum number of integers read at runtime
    and 'K' is the required order of number in sorted order.  
*/

#include<queue>

class Kthlargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;

    Kthlargest(int k, vector<int> &arr) {
        size = k;
        for (auto it:arr) {
            pq.push(it);
            if (pq.size() > size) {

                /*
                    Remove the top element from the queue as soon
                    as its size becomes greater than k.
                */
                pq.pop();             
            }
        }
    }

    void add(int num) {
        pq.push(num);
        if (pq.size() > size) {
            pq.pop();
        }

    }

    int getKthLargest() {

        /*
            The kth largest element will always
            be at the top of the queue.
        */
        return pq.top();     
    }

};
