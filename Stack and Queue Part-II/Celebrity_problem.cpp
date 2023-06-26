#include <bits/stdc++.h>
bool knows(vector<vector<int>> M, int a, int b)
{
    return M[a][b] == 1;
}
int findCelebrity(int n)
{
    // Write your code here.
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(a, b))
            s.push(b);
        else
            s.push(a);
    }

    int celeb = s.top();
    for (int i = 0; i < n; i++)
    {
        if (celeb != i && (knows(celeb, i) || !knows(i, celeb)))
            return -1;
    }
    return celeb;
}