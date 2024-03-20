//2812: 크게 만들기
//https://www.acmicpc.net/problem/2812
#include<iostream>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;

int N,K; // 받을 숫자
string X; // 받을 문자열
int cnt = 0;//현재까지 제외한 숫자 개수 카운터
int N_cnt = 0;//문자열의 현재 위치 포인터
deque<char> deq; //문자 제외에 사용할 덱

int main(){
    cin >> N >> K >> X;

    while(1){
        if(cnt == K){break;} //제외한 숫자의 개수가 K와 같으면 break

        if(N_cnt == N){ // 문자열을 전부 순회했다는 것은,문자열의 뒤에서 순서대로 삭제하면 된다는 뜻

            for(int i=0;i<K-cnt;i++){
                deq.pop_back(); // 문자열의 뒤에서 남은 K만큼 삭제
            }
            break;
        }

         if(deq.empty()){ //덱이 비었으면 덱에 숫자를 넣고 문자열 포인터를 ++
            deq.push_back(X[N_cnt]);
            N_cnt+=1;
         } else if(deq.back() >= X[N_cnt]){ // 덱 맨 뒤의 숫자가 크면 덱에 숫자를 넣고 문자열 포인터를 ++
            deq.push_back(X[N_cnt]);
            N_cnt+=1;
         } else if(deq.back() < X[N_cnt]){ // 덱 맨 뒤의 숫자가 작으면 그 숫자는 사라져야 한다.
            cnt += 1;
            deq.pop_back(); // 숫자를 없앴으므로 cnt 1 증가
         }
    }

    while(!deq.empty()){
        cout << deq.front();
        deq.pop_front();
    } // 덱에 남은 숫자 출력

    for(int i=N_cnt; i< X.size();i++){
        cout << X[i];
    } // N_cnt부터 문자열 마지막까지 남아있는 숫자 출력
}