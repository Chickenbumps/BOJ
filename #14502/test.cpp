#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int plusX[4] = {-1,0,1,0};
int plusY[4] = {0,1,0,-1};
int n,m;
int map[8][8];
int copymap[8][8];
vector<pair<int,int> > v;
 
void DFS(int x,int y){ //바이러스를 퍼트리기 위한 DFS
    for(int i=0; i<4; i++){
        int newX = plusX[i] + x;
        int newY = plusY[i] + y;
        if(newX>=0 && newX<n && newY>=0 && newY<m){
            if(copymap[newX][newY]==0){
                copymap[newX][newY] = 2;
                DFS(newX,newY);
            }
        }
    }
}
 
 
int main(){
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            copymap[i][j] = map[i][j];
            if(!map[i][j]) v.push_back(make_pair(i,j)); //0인 안전 영역의 위치만 벡터에 넣기. 그래야 0인곳의 위치 3개를 뽑아서 기둥 3개를 설치할수 있음.
        }
    }
    int MAX = 0;
    for(int i=0; i<v.size()-2; i++){
        for(int j=i+1; j<v.size()-1; j++){
            for(int k=j+1; k<v.size(); k++){
                pair<int,int> one = v[i];
                pair<int,int> two = v[j];
                pair<int,int> three = v[k]; //3개의 좌표 선택
                
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        copymap[i][j] = map[i][j];
                    }
                }
                
                //3개의 기둥 세우기
                copymap[one.first][one.second] = 1;
                copymap[two.first][two.second] = 1;
                copymap[three.first][three.second] = 1;
                
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(copymap[i][j] == 2)
                            DFS(i,j);
                    }
                } //기둥세우고 나서 DFS돌려서 바이러스 전파 시키기
                
//                cout<<endl;
//                for(int i=0; i<n; i++){
//                    for(int j=0; j<m; j++){
//                        cout<<copymap[i][j]<<" ";
//                    }cout<<endl;} //바이러스 잘 전파됬는지 확인하기
                
                int cnt = 0; //안전 영역 크기 확인
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(copymap[i][j] == 0)
                            cnt ++;
                    }
                }
                MAX = max(MAX,cnt);
            }
        }
    }
    cout<<MAX<<endl;
    
    
    
    return 0;
}

