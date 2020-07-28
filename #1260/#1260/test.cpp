#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1002

int edge[MAX][MAX];
bool visited[MAX];
int edgeNum;
int vertexNum;
int startNum;
queue<int>  q;

void init(){
    cin >> vertexNum >> edgeNum >> startNum;
    int to,from;
    memset(edge, 0, sizeof(edge));
    for (int i = 1 ; i <= edgeNum; ++i) {
        cin >> to >> from;
        edge[to][from] = 1;
        edge[from][to] = 1;
    }
}
void dfs(int start){
    visited[start] = true;
    cout << start << " ";
    for (int i = 1 ; i <= vertexNum; ++i) {
        if (!visited[i] && edge[start][i] == 1 && edge[i][start] == 1) {
            dfs(i);
        }
    }
}
void bfs(int start){
    visited[start] = 0;
    q.push(start);
    while(!q.empty()){
        start = q.front();
        cout << start << " ";
        q.pop();
        for (int i = 1; i <= vertexNum ; ++i) {
            if(visited[i] != 0 && edge[start][i] == 1 && edge[i][start] == 1 ){
                visited[i] = 0;
                q.push(i);
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    init();
    dfs(startNum);
    bfs(startNum);
    
    return 0;
}

