priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int> >  minHeap;
    int count;
    MedianFinder()
    {
        count=0;
    }
    
    void addNum(int num)
    {
        if (count % 2 == 0)
        {
            if(maxHeap.empty())
                maxHeap.push(num);
            else
            {
                if(num>maxHeap.top())
                {
                    minHeap.push(num);
                }
                else
                {
                    int temp=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
            }
        }
        else
        {
            if(minHeap.empty())
            {
                if(maxHeap.top()>num)
                {
                    int temp=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
                else
                    minHeap.push(num);
            }
            else
            {
                if(num<minHeap.top())
                {
                    maxHeap.push(num);
                }
                else
                {
                    int temp=minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                    minHeap.push(num);
                }
            }
        }
        count ++;
    }
    
    double findMedian()
    {
        if(minHeap.empty())
            return maxHeap.top();
        if(count&1)
            return minHeap.top();
        return (maxHeap.top()*1.0+minHeap.top()*1.0)/2.0;
    }