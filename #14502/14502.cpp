#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int i_N, i_M;
int i_Lab[8][8];
int i_CopyLab[8][8];
int i_plusX[4] = {-1, 0, 1, 0};
int i_plusY[4] = {0, 1, 0, -1};
vector<pair<int, int>> vp_V;

void VirusDFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int i_NewX = i_plusX[i] + x;
        int i_NewY = i_plusY[i] + y;
        if (i_NewX < i_N && i_NewX >= 0 && i_NewY < i_M && i_NewY >= 0)
        {
            if (i_CopyLab[i_NewX][i_NewY] == 0)
            {
                i_CopyLab[i_NewX][i_NewY] = 2;
                VirusDFS(i_NewX, i_NewY);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> i_N >> i_M; // i_N = Height of Lab , i_M = Width of Lab
    int i_MAX = 0;
    for (int i = 0; i < i_N; i++)
    {
        for (int j = 0; j < i_M; j++)
        {
            cin >> i_Lab[i][j];
            i_CopyLab[i][j] = i_Lab[i][j];
            if (i_Lab[i][j] == 0)
            {
                vp_V.push_back(make_pair(i, j)); // safe area will be save in vector.
            }
        }
    }
    for (int i = 0; i < vp_V.size() - 2; i++)
    {
        for (int j = i + 1; j < vp_V.size() - 1; j++)
        {
            for (int k = j + 1; k < vp_V.size(); k++)
            {
                pair<int, int> pi_FirstWall = vp_V[i];
                pair<int, int> pi_SecondWall = vp_V[j];
                pair<int, int> pi_ThirdWall = vp_V[k];

                for (int i = 0; i < i_N; i++)
                {
                    for (int j = 0; j < i_M; j++)
                    {
                        i_CopyLab[i][j] = i_Lab[i][j];
                    }
                }

                i_CopyLab[pi_FirstWall.first][pi_FirstWall.second] = 1;
                i_CopyLab[pi_SecondWall.first][pi_SecondWall.second] = 1;
                i_CopyLab[pi_ThirdWall.first][pi_ThirdWall.second] = 1;

                for (int i = 0; i < i_N; i++)
                {
                    for (int j = 0; j < i_M; j++)
                    {
                        if (i_CopyLab[i][j] == 2)
                        {
                            VirusDFS(i, j);
                        }
                    }
                }

                int i_Safearea = 0;
                for (int i = 0; i < i_N; i++)
                {
                    for (int j = 0; j < i_M; j++)
                    {
                        if (i_CopyLab[i][j] == 0)
                            i_Safearea++;
                    }
                }
                i_MAX = max(i_MAX, i_Safearea);
            }
        }
    }
    cout << i_MAX << "\n";
    return 0;
}
