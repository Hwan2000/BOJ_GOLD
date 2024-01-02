//10026: 토마토
//https://www.acmicpc.net/problem/10026
#include<iostream>
#include<queue>
#include<stack>
#include<iostream>

using namespace std;

int n = 0;

// 입력을 저장할 배열과 가 본 곳을 저장할 배열
char paint[101][101];
char RG_paint[101][101];
bool RG_visited[101][101] = {false,};
bool nomal_visited[101][101] = {false,};

// 방향지정 배열
int X_[4] = {0,0,1,-1};
int Y_[4] = {1,-1,0,0};

// 정답 저장용 배열
int answer_nomal[3] = {0,0,0};
int answer_RG[2] = {0,0};

/*
bfs 함수
입력: 탐색할 그림, 탐색에 저장할 boolean 배열, 정답 저장 배열을 받는다.
*/
void bfs(char paint[][101], bool visited[][101], int answer[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // 탐색할 그림 전체 탐색
            if(visited[i][j] == false){ // 가본적이 없다면
                char now_color = paint[i][j]; // 현재의 화소를 저장

                // 화소에 따라 정답 배열 업데이트
                if(now_color == 'R'){ answer[0] += 1;}
                if(now_color == 'B'){ answer[1] += 1;}
                if(now_color == 'G'){ answer[2] += 1;}

                queue<pair<int,int>> count_Q; // 탐색용 queue 생성

                count_Q.push({i,j}); // queue에 현재 위치 삽입
                visited[i][j] = true; // 현재 위치는 방문한 것으로

                while(!count_Q.empty()){ // queue가 빌 때까지
                    pair<int,int> now = count_Q.front();// queue 맨 앞의 원소를 꺼낸 뒤 삭제
                    count_Q.pop();

                
                    for(int ii=0;ii<4;ii++){ // 4방향의 화소를 확인
                        int next_x = now.first + X_[ii];
                        int next_y = now.second + Y_[ii];

                        if(next_x < 0 || next_y < 0 || next_x > n || next_y > n)continue; // 범위를 벗어나면 continue

                        if(paint[next_x][next_y] == now_color && visited[next_x][next_y] == false){ //가본 적도 없고 현재 화소와 일치하면
                            count_Q.push({next_x,next_y}); // 그 위치를 queue에 삽입
                            visited[next_x][next_y] = true; // 해당 위치는 가본 것으로 저장
                        }
                    }   
                }

            }
        }
    }
}

int main(void){
    cin >> n;

    // 입력은 R,G,B로 저장하면서 적록색맹용 입력은 G를 R로 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> paint[i][j];

            if (paint[i][j] == 'R') {
                RG_paint[i][j] = 'R';
            } else if (paint[i][j] == 'G') {
                RG_paint[i][j] = 'R'; // 해당 부분
            } else if (paint[i][j] == 'B') {
                RG_paint[i][j] = 'B';
            }
        }
    }

    bfs(paint, nomal_visited, answer_nomal); // RGB 배열로 bfs 실행
    bfs(RG_paint, RG_visited, answer_RG); // RB 배열로 bfs 실행

    // 정답 출력
    cout << answer_nomal[0] + answer_nomal[1] + answer_nomal[2] << ' ' << answer_RG[0] + answer_RG[1];
    
}