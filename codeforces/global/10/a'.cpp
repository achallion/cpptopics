#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n & 1)
        cout << 0;
    else
        cout << (1 << (n / 2));
    return 0;
}