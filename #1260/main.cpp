#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int visit[1001];
int i_Dot,i_Line;
void Dfs(int start ){
    cout << start<< " ";
    visit[start] = 1;
    for (int i = 1; i <= i_Dot; ++i) {
        if(visit[i] != 1 && arr[start][i] == 1)
        {
            Dfs(dot,i);
        }
    }
}

void Bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] =0 ;
    while(!q.empty())
    {
        start = q.front();
        cout << q.front() << " ";
        q.pop();
        for (int i = 1; i <= i_Dot ; ++i) {
            if(visit[i]  != 0 && arr[start][i] == 1)
            {
                q.push(i);
                visit[i] = 0;
            }
        }
    }

}

int main() {
    cin >> i_Dot>>i_Line;
    int i_Start;
    cin >> i_Start;
    int temp1,temp2;
    for (int k = 1; k <= i_Line; ++k) {
        cin >> temp1 >> temp2;
        arr[temp1][temp2] = arr[temp2][temp1]=1;
    }

    Dfs(i_Start);
    cout << '\n';
    Bfs(i_Start);
    return 0;
}