#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int map[1010];
    int dp1[1010];
    int dp2[1010];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = 1;
        dp2[i] = 1;
    }
    int max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (map[i] < map[j])
                dp1[j] = max(dp1[i] + 1, dp1[j]);
            max1 = max(max1, dp1[j]);
        }
    }
    int max2 = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            if (map[i] < map[j])
            {
                dp2[j] = max(dp2[j], dp2[i] + 1);
            }
            max2 = max(max2, dp2[j]);
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = max(dp1[i] + dp2[i], result);
    }
    cout << result - 1 << endl;
    return 0;
}