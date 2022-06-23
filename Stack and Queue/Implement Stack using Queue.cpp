#include <bits/stdc++.h>
using namespace std;
class Stack {
 
    queue<int> q;
 
public:
    void push(int data);
    void pop();
    int top();
    bool empty();
};

void Stack::push(int data)
{
    int s = q.size();
    q.push(data);
    for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
    }
}
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
int Stack::top() { return (q.empty()) ? -1 : q.front(); }
bool Stack::empty() { return (q.empty()); }
 
int main()
{
    Stack st;
    st.push(40);
    st.push(50);
    st.push(70);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.push(80);
    st.push(90);
    st.push(100);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    return 0;
}