#include <iostream>
#include <vector>
using namespace std;

void min_and_max(vector<int> inp)
{
    int max, min;
    if (inp[0] > inp[1])
    {
        max = inp[0];
        min = inp[1];
    }
    else
    {
        max = inp[1];
        min = inp[0];
    }
    for (int iter = 2; iter < inp.size() - 1; iter++)
    {
        int num1 = inp[iter];
        int num2 = inp[iter + 1];

        int temp1, temp2; // temp 1 for temporary max and temp 2 for temporary min
        if (num1 > num2)
        {
            temp1 = num1;
            temp2 = num2;
        }
        if (temp1 > max)
            max = temp1;
        if (temp2 < min)
            min = temp2;
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
}
int main()
{
    vector<int> inp = {1, 4, 5, 3, 2, 6};
    min_and_max(inp);
    return 0;
}