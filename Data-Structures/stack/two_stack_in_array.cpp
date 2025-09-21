#include <iostream>
#include <vector>
using namespace std;

class nStackArray
{
private:
    vector<int> stk;
    vector<int> next;
    vector<int> top;
    size_t free_index;

public:
    // size is the size of the global array, n is the number of stacks to be implemented in the array
    nStackArray(int size, size_t n)
    {
        stk.resize(size);
        next.resize(size, 0);
        top.resize(n, -1);
        this->free_index = 0;

        for (int i = 1; i < size; i++)
        {
            next[i - 1] = i;
        }
        next[size - 1] = -1;
    }
    bool isEmpty(size_t stkNo)
    {
        return top[stkNo] == -1;
    }
    bool isFull()
    {
        return free_index == -1;
    }
    void push(int val, size_t stkNo)
    {
        if (!isFull())
        {
            int i = free_index;
            free_index = next[i];

            next[i] = top[stkNo];
            stk[i] = val;
            top[stkNo] = i;
        }
        else
        {
            cout << "OVERFLOW" << endl;
        }
    }
    int pop(size_t stkNo)
    {
        if (!isEmpty(stkNo))
        {
            int popVal = stk[top[stkNo]];

            int i = next[top[stkNo]];
            next[top[stkNo]] = free_index;
            free_index = top[stkNo];
            top[stkNo] = i;

            return popVal;
        }
        else{
            cout << "UNDERFLOW" << endl;
        }
    }
    void displayStack(size_t stkNo)
    {
        while (top[stkNo] >= 0)
        {
            int t = top[stkNo];
            cout << stk[t] << " ";
            top[stkNo] = next[top[stkNo]];
        }
        cout << endl;
    }
};
int main()
{
    nStackArray stk(4, 3);
    stk.push(1, 0);
    stk.push(2, 1);
    stk.push(3, 2);
    stk.push(4, 0);

    stk.displayStack(2);
    stk.displayStack(1);
    stk.displayStack(0);
    return 0;
}