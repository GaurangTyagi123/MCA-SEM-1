#include <iostream>
#include "queue.cpp"

void queueRev(LQueue<int> &q, int ele)
{
    if (q.isEmpty())
    {
        q.enqueue(ele);
    }
    else
    {
        queueRev(q, q.dequeue());
        q.enqueue(ele);
    }
}
int main()
{
    LQueue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    queueRev(q, q.dequeue());

    q.displayQueue();
    return 0;
}