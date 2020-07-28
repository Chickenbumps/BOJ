#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define MAX 50

char map[MAX][MAX];
int visited[MAX][MAX];
int countLength;
int width,height;
int maxLength = 0;
int y[] = {1, -1, 0, 0};
int x[] = {0, 0, 1, -1};

void init(){
    cin >> height >> width;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            cin >> map[i][j];
}


void bfs(int col, int row){
    memset(visited, 0, sizeof(visited));
    queue< pair<int,int> > q;
    visited[col][row] = 1;
    q.push(make_pair(col,row));
    while(!q.empty()){
        col = q.front().first;
        row = q.front().second;
         q.pop();
        for(int i = 0; i < 4; i++){
            int c = col + y[i];
            int r = row + x[i];
            if(c < height && c > -1 && r < width && r > -1){
                if(visited[c][r] == 0 && map[c][r] == 'L'){
                    visited[c][r] = visited[col][row] + 1;
                    countLength = max(countLength, visited[c][r]);
                    q.push(make_pair(c,r));
                }
            }
        }

    }
}


int main(void){
    init();
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(map[i][j] == 'L'){
                bfs(i,j);
                maxLength = max(countLength,maxLength);
                countLength = 0;
            }
        }
    }
    cout << maxLength -1;
    return 0;
}
