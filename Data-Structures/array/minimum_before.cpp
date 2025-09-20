#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void minimum_before(vector<int> inp, vector<int> &res)
{
    stack<int> stk;
    res[0] = -1;
    stk.push(inp[0]);
    for (int iter = 1; iter < inp.size(); iter++)
    {
        while (!stk.empty())
        {
            int temp = stk.top();
            if (temp < inp[iter])
            {
                res[iter] = temp;
                break;
            }
            else
            {
                stk.pop();
            }
        }
        if (stk.empty())
        {
            res[iter] = -1;
        }
        stk.push(inp[iter]);
    }
}

int main()
{
    vector<int> inp = {1, 4, 5, 3, 2, 6};
    vector<int> res;
    res.resize(inp.size());

    minimum_before(inp, res);

    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}