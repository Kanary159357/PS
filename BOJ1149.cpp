#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[1001][3];
int a[1001][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }
    a[0][0] = map[0][0];
    a[0][1] = map[0][1];
    a[0][2] = map[0][2];
    for (int i = 1; i < n; i++)
    {
        a[i][0] = min(a[i - 1][1], a[i - 1][2]) + map[i][0];
        a[i][1] = min(a[i - 1][0], a[i - 1][2]) + map[i][1];
        a[i][2] = min(a[i - 1][0], a[i - 1][1]) + map[i][2];
    }
    int result = min(a[n - 1][0], min(a[n - 1][1], a[n - 1][2]));
    cout << result << endl;
    return 0;
}