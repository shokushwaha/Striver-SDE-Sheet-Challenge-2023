class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxs;
    int mins;

public:
    MedianFinder()
    {
        maxs = 0;
        mins = 0;
    }

    void addNum(int num)
    {
        maxHeap.push(num);
        maxs++;

        minHeap.push(maxHeap.top());
        mins++;

        maxHeap.pop();
        maxs--;

        if (mins > maxs)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxs++;
            mins--;
        }
    }

    double findMedian()
    {
        if (maxs == mins)
            return (maxHeap.top() + minHeap.top()) / 2.0;

        else
            return maxHeap.top();
    }
};
