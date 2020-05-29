/*

Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
    
*/

class MedianFinder {
    void rebalance()
    {
         int size1 = maxHeap.size(), size2 = minHeap.size(); 
        if(size1 > size2+1)
        {
            auto p = maxHeap.top();
            maxHeap.pop();
            minHeap.push(p);
        }
        else if(size2 > size1)  //because of this check, avg will always be there at the top of max heap in case of odd count of numbers
        {
            auto p = minHeap.top();
            minHeap.pop();
            maxHeap.push(p);
        }
    }
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        if(maxHeap.empty())  
        {
          maxHeap.push(num);
          return;
        }
        int top1 = maxHeap.top();
        if(num < top1)
            maxHeap.push(num);
        else
            minHeap.push(num);            
        rebalance();
    }
    
    double findMedian() {
        int size1 = maxHeap.size(), size2 = minHeap.size(); 
        if((size1 + size2) % 2 == 0)
        {
            return 0.5 * (maxHeap.top() + minHeap.top());
        }
        else
        {
            return maxHeap.top();            
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
