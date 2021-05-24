#include <iostream>
#include <queue>
#include <vector>
int n = -1, m = -1;
using namespace std;
int map[52][52];
int visited[52][52];
struct T
{
    int y, x;
};
queue<T> q;
vector<T> v;
int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void bfs()
{
    while (!q.empty())
    {
        int dy = q.front().y;
        int dx = q.front().x;
        q.pop();
        ;
        for (int i = 0; i < 8; i++)
        {
            int ty = dir[i][0] + dy;
            int tx = dir[i][1] + dx;
            if (map[ty][tx] == 1 && !visited[ty][tx] && ty >= 0 && tx >= 0 && ty < n && tx < m)
            {
                visited[ty][tx] = 1;
                q.push({ty, tx});
            }
        }
    }
};

int main()
{
    while (1)
    {
        fill(&map[0][0], &map[0][0] + 52 * 52, 0);
        fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
        v.clear();
        cin >> m >> n;
        if (!m && !n)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 1)
                    v.push_back({i, j});
            }
        }
        int result = v.size();
        for (int i = 0; i < v.size(); i++)
        {
            if (visited[v[i].y][v[i].x] == 0)
            {
                visited[v[i].y][v[i].x] = 1;
                q.push(v[i]);
                bfs();
            }
            else
            {
                result--;
            }
        }
        cout << result << endl;
    }
}