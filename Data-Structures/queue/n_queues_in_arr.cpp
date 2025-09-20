#include <iostream>
#include <vector>
using namespace std;

class NQueue
{
private:
    vector<int> front;
    vector<int> rear;
    vector<int> next;
    int freeIndex = 0;
    vector<int> arr;
    size_t n;
    size_t k;

public:
    NQueue(size_t n, size_t k)
    {
        this->n = n;
        this->k = k;
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n, 0);
        arr.resize(n);

        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = 1;
    }
    bool isFull()
    {
        return this->freeIndex == -1;
    }
    bool isEmpty(size_t qn)
    {
        return this->front[qn] == -1;
    }
    void enqueue(int val, size_t qn)
    {
        if (this->isFull())
        {
            cout << "OVERFLOW" << endl;
        }
        size_t i = this->freeIndex;
        this->freeIndex = next[i];

        if (this->isEmpty(qn))
        {
            front[qn] = i;
        }
        else
        {
            next[rear[qn]] = i;
        }
        rear[qn] = i;
        arr[i] = val;
        next[i] = -1;
    }
    int dequeue(size_t qn)
    {
        if (this->isEmpty(qn))
        {
            cout << "UNDERFLOW" << endl;
        }
        int i = front[qn];
        front[qn] = next[i];

        if (front[qn] == -1)
        {
            rear[qn] = -1;
        }
        next[i] = freeIndex;
        freeIndex = i;

        return this->arr[i];
    }
    void displayQueue(size_t qn)
    {
        int iter = front[qn];
        while(iter !=-1){
            cout << arr[iter] << endl;
            iter = next[iter];
        }
    }
};
int main()
{
    NQueue q(5, 3);
    q.enqueue(10, 0);
    q.enqueue(20, 1);
    q.enqueue(30, 0);

    q.displayQueue(0);
    return 0;
}