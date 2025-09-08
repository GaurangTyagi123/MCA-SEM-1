#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void interleaveQ(queue<int> &q){
    stack<int> stk;
    int len = q.size();
    if(!(len%2)){
        for (size_t iter = 0; iter < len / 2;iter++){
            stk.emplace(q.front());
            q.pop();
        }
        for (size_t iter = 0; iter < len / 2;iter++){
            q.emplace(stk.top());
            stk.pop();
        }
        for (size_t iter = 0; iter < len / 2;iter++){
            q.emplace(q.front());
            q.pop();
        }
        for (size_t iter = 0; iter < len / 2;iter++){
            stk.emplace(q.front());
            q.pop();
        }
        while(!stk.empty()){
            q.emplace(stk.top());
            stk.pop();
            q.emplace(q.front());
            q.pop();
        }
    }
    else{
        cout << "Queue is not of even length" << endl;
    }
}
void displayQ(queue<int> q){
    while(!q.empty()){
        cout << q.front() << "-";
        q.pop();
    }
    cout << endl;
}
int main(){
    queue<int> q;
    q.emplace(2);
    q.emplace(4);
    q.emplace(3);
    q.emplace(1);

    interleaveQ(q);
    displayQ(q);
    return 0;
}