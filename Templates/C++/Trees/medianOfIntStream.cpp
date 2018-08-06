//
// Code Contributor(s) : Rajeev Ranjan
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    priority_queue<int, vector<int> ,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int curr;
    float median = 0.0;
    while(cin>>curr)
    {
        if(minHeap.size() == maxHeap.size())
        {
            if(curr < median)
            {
                maxHeap.push(curr);
                median = maxHeap.top();
                cout<<"Current Median "<<(int)median<<" ";
            }
            else
            {
                minHeap.push(curr);
                median = minHeap.top();
                cout<<"Current Median "<<(int)median<<" ";
            }
        }
        else if(minHeap.size() < maxHeap.size())
        {
            if(curr < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(curr);
            }
            else
            {
                minHeap.push(curr);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
            cout<<"Current Median "<<median<<" ";
        }
        else
        {
            if(curr < median)
            {
                maxHeap.push(curr);
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(curr);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;
            cout<<"Current Median "<<median<<" ";
        }
    }
    return 0;
}
