#include <iostream>
#include <algorithm>
using namespace std;

struct T
{
    long s, e;
};

bool sorter(T a, T b)
{
    if (a.e == b.e)
    {
        return a.s < b.s;
    }
    return a.e < b.e;
}

int main()
{
    int n;
    cin >> n;
    T a[1000000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s >> a[i].e;
    }
    sort(a, a + n, sorter);

    int cnt = 0;
    long last = -1;
    int curindex = -1;

    while (1)
    {
        int flag = 0;
        for (int i = curindex + 1; i < n; i++)
        {
            if (a[i].s >= last)
            {
                last = a[i].e;
                flag = 1;
                curindex = i;
                break;
            }
        }
        if (flag == 0)
            break;
        cnt++;
    }
    cout << cnt << endl;
}