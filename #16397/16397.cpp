
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000
bool state[MAX];

int Abutton(int num)
{
    return ++num;
}

int Bbutton(int num)
{
    int temp = 10000;
    num = num * 2;
    if (num > 99999)
        return 0;
    while (true)
    {
        if (num / temp != 0)
        {
            num = num - temp;
            return num;
        }
        else
        {
            temp /= 10;
        }
    }
}

int BFS(int n, int g, int T)
{
    queue<int> q;
    int i = 0;
    int icurrent;
    q.push(n);
    state[n] = 1;
    while (!q.empty())
    {
        icurrent = q.front();
        q.pop();

        if (T < i)
            break;
        if (icurrent == g)
            return i;
        int A = Abutton(n);
        int B = Bbutton(n);

        if (A < MAX && state[A] != 1)
        {
            q.push(A);
            ++i;
            state[A] = 1;
        }

        if (B < MAX && state[B] != 1)
        {
            q.push(B);
            ++i;
            state[B] = 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int N, T, G;
    int iResult = 0;
    cin >> N >> T >> G;
    iResult = BFS(N, G, T);

    if (iResult == -1)
    {
        cout << "ANG"
             << "\n";
    }
    else
    {
        cout << iResult << "\n";
    }

    return 0;
}
