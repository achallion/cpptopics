#include <bits/stdc++.h>

using namespace std;

void build(int *a, int s, int e, vector<int> &segtree, int i)
{
    // base
    if (s == e)
    {
        segtree[i] = a[s];
        return;
    }

    // end
    int mid = (s + e) / 2;
    build(a, s, mid, segtree, 2 * i);
    build(a, mid + 1, e, segtree, 2 * i + 1);
    segtree[i] = min(segtree[2 * i], segtree[2 * i + 1]);
}

void print(const vector<int> &seg)
{
    int n = seg[0];
    for (int i = 1; i < seg.size(); i++)
    {
        cout << seg[i] << " ";
    }
}

int query(vector<int> &seg, int s, int e, int qs, int qe, int i)
{
    // base
    if (s >= qs && e <= qe) // complete overlap
    {
        return seg[i];
    }
    if (s > qe || qs > e) // no overlap
    {
        return INT_MAX;
    }

    // rec
    int mid = (s + e) / 2;
    int m1 = query(seg, s, mid, qs, qe, 2 * i);
    int m2 = query(seg, mid + 1, e, qs, qe, 2 * i + 1);
    return min(m1, m2);
}

void updateelement(vector<int> &seg, int s, int e, int elei, int inc, int i)
{
    // base
    if (s == e && s == elei)
    {
        seg[i] += inc;
        return;
    }

    if (elei > e || elei < s)
    {
        return;
    }

    // rec
    int mid = s + e;
    mid >>= 1;
    updateelement(seg, s, mid, elei, inc, i << 1);
    updateelement(seg, mid + 1, e, elei, inc, (i << 1) + 1);
    seg[i] = min(seg[i << 1], seg[(i << 1) + 1]);
}

void updaterange(vector<int> &seg, int s, int e, int l, int r, int inc, int i)
{
    // base
    if (l > e || r < s)
    {
        return;
    }

    if (s == e)
    {
        seg[i] += 10;
        return ;
    }

    // rec
    cout << s << " " << e << "\n"
         << flush;
    int mid = s + e;
    mid >>= 1;
    updaterange(seg, s, mid, l, r, inc, i << 1);
    updaterange(seg, mid + 1, e, l, r, inc, (i << 1) + 1);
    seg[i] = min(seg[i << 1], seg[(i << 1) + 1]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> segtree(4 * n + 1);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    segtree[0] = n;
    build(a, 0, n - 1, segtree, 1);
    while (true)
    {
        int op;
        system("clear");
        cout << "\n1. print \n2.Query \n3. Update Element \n4. Update Range \n5. Exit\n\n";
        cin >> op;
        system("clear");
        if (op == 5)
        {
            break;
        }
        switch (op)
        {
        case 1:
            print(segtree);
            break;
        case 2:
            int si2, ei2;
            cout << "\nGive Start index : ";
            cin >> si2;
            cout << "\nGive End index :";
            cin >> ei2;
            cout << query(segtree, 0, n - 1, si2, ei2, 1);
            break;
        case 3:
            int ind, inc3;
            cout << "\nGive index : ";
            cin >> ind;
            cout << "\nGive increment : ";
            cin >> inc3;
            updateelement(segtree, 0, n - 1, ind, inc3, 1);
            break;
        case 4:
            int si, ei, inc;
            cout << "\nStart Index : ";
            cin >> si;
            cout << "\nEnd index : ";
            cin >> ei;
            cout << "\nIncrement : ";
            cin >> inc;
            updaterange(segtree, 0, n - 1, si, ei, inc, 1);
            break;
        }
    }
    delete[] a;
    return 0;
}