#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int map[10010];
    int n;
    int dp[10010];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
    }
    dp[1] = map[1];
    dp[2] = map[1] + map[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + map[i], dp[i - 3] + map[i] + map[i - 1]));
    }
    cout << dp[n] << endl;
}