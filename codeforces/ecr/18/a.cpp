#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int mind = INT_MAX;
    int minc = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = a[i] - a[i - 1];
        if (diff == mind)
        {
            minc++;
            continue;
        }
        if (diff < mind)
        {
            mind = diff;
            minc = 1;
        }
    }
    cout << mind << " " << minc;
    delete[] a;
    return 0;
}