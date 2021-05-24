#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int temp[1000000];
int main()
{
    int n;
    cin >> n;
    fill(&temp[0], &temp[0] + 1000000, 999999);

    temp[n] = 0;
    int cur = n;
    for (int cur = n; cur >= 0; cur--)
    {
        if (cur % 3 == 0 && temp[cur / 3] > temp[cur])
        {
            temp[cur / 3] = temp[cur] + 1;
        }
        if (cur % 2 == 0 && temp[cur / 2] > temp[cur])
        {
            temp[cur / 2] = temp[cur] + 1;
        }
        if (temp[cur - 1] > temp[cur])
        {
            temp[cur - 1] = temp[cur] + 1;
        }
    }

    cout << temp[1] << endl;
}