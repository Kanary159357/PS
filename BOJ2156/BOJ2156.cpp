#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int map[10010];
    int re[10010][4];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
    }
    re[1][0] = 0;
    re[1][2] = 0;
    re[1][1] = map[1];
    re[2][0] = map[1];
    re[2][1] = map[2];
    re[2][2] = map[1] + map[2];
    for (int i = 3; i <= n; i++)
    {
        re[i][0] = max(re[i - 1][2], max(re[i - 1][1], max(re[i - 2][1], re[i - 2][2])));
        re[i][1] = max(re[i - 1][0] + map[i], re[i - 2][0] + map[i]);
        re[i][2] = re[i - 1][1] + map[i];
    }
    cout << max(re[n][0], max(re[n][1], re[n][2])) << endl;
}