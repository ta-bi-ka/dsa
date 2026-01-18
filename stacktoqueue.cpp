#include<bits\stdc++.h>
using namespace std;
class queueUsingStacks
{
    stack<int> s1;
    stack<int> s2;
public:
    queueUsingStacks()
    {
    }

    void enqueue(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

    }

    int dequeue()
    {
       
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int front()
    {
       
        return s1.top();
    }

    bool isEmpty()
    {
        return s1.empty();
    }
};
