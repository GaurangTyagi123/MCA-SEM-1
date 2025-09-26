#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &arr){
    size_t start = 0;
    size_t end = arr.size() - 1;
    while(start<end){
        swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main()
{
    vector<int> v = {1,4,5,3,2,6};
    reverse(v);
    for(auto iter:v){
        cout << iter << " ";
    }
    cout << endl;
    return 0;
}