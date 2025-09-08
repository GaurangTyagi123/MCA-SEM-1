#include <iostream>
#include <stack>
#include "queue.cpp"
using namespace std;

void reverse_k_queue(size_t k, LQueue<int> &q)
{
    stack<int> tempStack;
    LQueue<int> tempQ;
    size_t len = 0;

    for (size_t iter = 0; iter < k; iter++)
    {
        int val = q.dequeue();
        tempStack.push(val);
        ++len;
    }
    for (size_t iter = 0; iter < k; iter++)
    {
        int val = tempStack.top();
        q.enqueue(val);
        tempStack.pop();
    }
    for (size_t iter = 0; iter < k; iter++)
    {
        int val = q.dequeue();
        q.enqueue(val);
    }
}
int main()
{
    LQueue<int> q;

    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    reverse_k_queue(4, q);
    q.displayQueue();
    return 0;
}