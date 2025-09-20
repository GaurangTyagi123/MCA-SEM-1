#include <iostream>
#include <stack>

using namespace std;

class SQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        if (s1.empty())
        {
            s1.emplace(val);
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s2.emplace(temp);
                s1.pop();
            }
            s1.emplace(val);
            while (!s2.empty())
            {
                s1.emplace(s2.top());
                s2.pop();
            }
        }
    }
    int dequeue()
    {
        if (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            return temp;
        }
        else{
            return -1;
        }
    }
};

int main()
{
    SQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}