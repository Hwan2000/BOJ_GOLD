//2589: 보물섬
//https://www.acmicpc.net/problem/2589
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char map[51][51];

int _X[4] = {-1,1,0,0};
int _Y[4] = {0,0,-1,1};

int N,M;

int answer = 0;

int main(){
    cin >> N >> M;
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            cin >> map[n][m];
        }
    }

    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            if(map[n][m] == 'W') continue;

            int large = 0;

            int visitied[51][51] = {0,};

            queue<pair<int,int>> Q; Q.push({n,m}); visitied[n][m] = 1;

            while(!Q.empty()){
                pair<int,int> now = Q.front();Q.pop();
                int now_value = visitied[now.first][now.second];
                for(int i=0;i<4;i++){
                    int next_X = now.first + _X[i];
                    int next_Y = now.second + _Y[i];
                    if(next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M) continue;
                    if(map[next_X][next_Y] == 'L' && visitied[next_X][next_Y] == 0){
                        visitied[next_X][next_Y] = now_value + 1;
                        Q.push({next_X,next_Y});
                        if(now_value > large){
                            large = now_value;
                        }
                    }
                }
            }
            if(large>answer){
                answer = large;
            }
        }
    }
    cout << answer;
}