// using two queeus -
class Stack
{
    // Define the data members.
private:
    queue<int> q1, q2;
    int length;

public:
    Stack()
    {
        // Implement the Constructor.
        length = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return length;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return length == 0;
    }

    void push(int element)
    {
        // Implement the push() function.
        q2.push(element);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        length++;
    }

    int pop()
    {
        // Implement the pop() function.
        if (!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            length--;
            return x;
        }
        return -1;
    }

    int top()
    {
        // Implement the top() function.
        if (!q1.empty())
            return q1.front();

        return -1;
    }
};

// using one queue -
#include <bits/stdc++.h>

class Stack
{

    // Define the data members.
private:
    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        if (q.empty())
            return true;
        else
            return false;
    }

    void push(int element)
    {
        // Implement the push() function.
        q.push(element);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (!q.empty())
        {
            int ans = q.front();
            q.pop();
            return ans;
        }

        return -1;
    }

    int top()
    {
        // Implement the top() function.
        if (!q.empty())
            return q.front();

        return -1;
    }
};
