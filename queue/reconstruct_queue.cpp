#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    vector<vector<int>>::iterator first = people.begin();
    vector<vector<int>>::iterator last = people.end();

    sort(first, last, comp);
    vector<vector<int>> temp;
    for (auto it : people)
    {
        temp.insert(temp.begin() + it[1], it);
    }

    people = temp;
    return people;
}
int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    people = reconstructQueue(people);
    for (auto it1 : people)
    {
        for (auto it2 : it1)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}