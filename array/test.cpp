#include <iostream>
#include "array.cpp"
using namespace std;

int main(){
    Array<int> arr(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);
    arr.pop(2);
    arr.insertAt(2, 7);

    arr.displayList();
    return 0;
}