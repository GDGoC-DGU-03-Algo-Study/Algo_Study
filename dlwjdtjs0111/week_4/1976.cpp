#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N));

    vector<int> plan(M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        G[i][i] = 1;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (G[i][k] == 1 && G[k][j] == 1)
                {
                    G[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> plan[i];
        plan[i]--;
    }

    int currentIndex = 0;
    bool success = false;
    for (int i = 0; i < M - 1; i++)
    {
        if (G[plan[i]][plan[i + 1]] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}