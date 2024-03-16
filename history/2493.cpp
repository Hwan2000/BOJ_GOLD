//2493: 탑
//https://www.acmicpc.net/problem/2493
#include<iostream>
#include<stack>

using namespace std;

int N;
int answer[500001];
stack<pair<int,int>> S;

int main(){
    cin >> N;
    int x;

    for(int i=1;i<=N;i++){
        cin >> x;

        // 기존 탑이 새 탑보다 작으면 어차피 쓸 일이 없다.
        while(!S.empty() && S.top().first < x){
            S.pop();
        }

        // 비어있으면 신호를 받아 줄 탑은 없다.
        // 비어있지 않으면 스택의 맨 위의 탑 길이가 받게 된다
        if(S.empty()){
            answer[i] = 0;
        } else {
            answer[i] = S.top().second;
        }

        S.push({x,i});
        
    }

    for(int i=1;i<=N;i++){
        cout << answer[i] << ' ';
    }

    
}