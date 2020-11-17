#include <bits/stdc++.h>

using namespace std;

int solve(string A)
{
    stack<char> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(')
            s.push('(');
        else if (s.empty())
            return 0;
        else
            s.pop();
    }

    return s.empty();
}

