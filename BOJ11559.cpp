#include <iostream>
#include <queue>
char map[12][6];
int visited[12][6];
using namespace std;

struct T
{
    int y, x, color;
};
queue<T> q;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int result = 0;
bool change = true;

void getDown()
{
    for (int j = 0; j < 6; j++)
    {
        int h = 0;
        for (int i = 11; i >= 0; i--)
        {
            if (map[i][j] == '.')
            {
                h++;
            }
            else
            {
                if (h > 0)
                {
                    map[h + i][j] = map[i][j];
                    map[i][j] = '.';
                }
            }
        }
    }
}

void bfs(int y, int x, char color)
{
    int max1 = 1;
    q.push({y, x, color});
    visited[y][x] = 1;
    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        char color = q.front().color;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            if (visited[dy][dx] == 0 && dy < 12 && dy >= 0 && dx < 6 && dx >= 0 && map[dy][dx] == color)
            {
                q.push({dy, dx, color});
                visited[dy][dx] = 1;
                max1++;
            }
        }
    }
    if (max1 >= 4)
    {
        change = true;
        for (int i = 11; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (visited[i][j])
                    map[i][j] = '.';
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> map[i][j];
        }
    }
    while (change == true)
    {
        change = false;
        for (int i = 11; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.')
                {
                    fill(&visited[0][0], &visited[0][0] + 12 * 6, 0);
                    bfs(i, j, map[i][j]);
                }
            }
        }
        if (change)
            result++;
        getDown();
    }
    cout << result << endl;
}