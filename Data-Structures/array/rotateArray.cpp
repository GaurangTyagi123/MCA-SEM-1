#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp;
    size_t len = nums.size();
    k = k % len;
    size_t iter = 0;

    for (int i = 0; i < k; i++)
    {
        temp.push_back(nums.at(len - k + i));
    }

    for (int i = len - k - 1; i >= 0; --i)
    {
        nums[i + k] = nums[i];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }
}
int main()
{
    vector<int> nums = {1, 2};
    rotate(nums, 7);
    for (auto i : nums)
    {
        cout << i << endl;
    }
    return 0;
}