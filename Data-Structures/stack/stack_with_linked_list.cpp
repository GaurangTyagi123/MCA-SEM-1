#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    LStack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    // stk.push(7);

    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    stk.displayStack();
    return 0;
}