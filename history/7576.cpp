//7576: 토마토
//https://www.acmicpc.net/problem/7576
#include<iostream>
#include<queue>

using namespace std;

int box[1001][1001];
int M,N;
int zero_check = 0;
int X_[4] = {-1,1,0,0};
int Y_[4] = {0,0,-1,1};

int main(){
    cin >> M >> N;
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            cin >> box[n][m];
            if(box[n][m] != 0) { zero_check++; }
        }
    }

    if(zero_check == M*N){
        cout << 0;
        return 0;
    }

    queue<pair<int,int>> Q;

    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            if(box[n][m] == 1) {Q.push({n,m});}
        }
    }

    while(!Q.empty()){
        pair<int,int> now = Q.front();Q.pop();
        int nowvalue = box[now.first][now.second];
        for(int i=0;i<4;i++){
            int next_X = now.first + X_[i];
            int next_Y = now.second + Y_[i];

            if(next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M) continue;

            if(box[next_X][next_Y] == 0){
                box[next_X][next_Y] = nowvalue+1;
                Q.push({next_X,next_Y});
            }
        }
    }

    int anser = 0;

    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            if(box[n][m] == 0) { cout << -1; return 0;}
            if(anser < box[n][m]) {anser = box[n][m];}
        }
    }

    cout << anser-1;
}
