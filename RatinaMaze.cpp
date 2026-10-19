#include <iostream>
#include <string>
using namespace std;

const int MAX = 4;

int N;
int maze[MAX][MAX];
int visited[MAX][MAX];

bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

void findPaths(int x, int y, string path)
{
    if (x == N - 1 && y == N - 1)
    {
        cout<<path<<endl;
        return;
    }

    visited[x][y] = 1;

    if (isSafe(x + 1, y))
    {
        findPaths(x + 1, y, path + "D");
    }

    if (isSafe(x, y - 1))
    {
        findPaths(x, y - 1, path + "L");
    }

    if (isSafe(x, y + 1))
    {
        findPaths(x, y + 1, path + "R");
    }

    if (isSafe(x - 1, y))
    {
        findPaths(x - 1, y, path + "U");
    }

    visited[x][y] = 0;
}

int main()
{
    cout<<"Enter size of maze: ";
    cin>>N;

    cout<<"Enter maze (0/1):"<<endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>maze[i][j];
            visited[i][j] = 0;
        }
    }

    if (maze[0][0] == 0 || maze[N - 1][N - 1] == 0)
    {
        cout<<"No path exists!"<<endl;
        return 0;
    }

    cout<<"All possible paths:"<<endl;

    findPaths(0, 0, "");

    return 0;
}
