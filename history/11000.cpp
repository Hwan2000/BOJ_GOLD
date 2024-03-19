//11000: 강의실 배정
//https://www.acmicpc.net/problem/11000
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;
pair<int,int> lesson[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> N;
    
    // 입력
    for(int i=0;i<N;i++){
        cin >> lesson[i].first >> lesson[i].second;
    }

    // 강의 시작 시간에 따라 정렬
    sort(lesson, lesson+N);

    // 최초 원소 삽입 -> 어차피 강의가 끝나는 시간만 중요하다.
    pq.push(lesson[0].second);

    for(int i=1;i<N;i++){
        if(pq.top() > lesson[i].first){ // 해당 강의보다 먼저 끝나는 강의가 없다면
            pq.push(lesson[i].second); // 새로운 강의로 삽입
        } else { // 해당 강의보다 같거나 먼저 끝난 강의가 있다면
            pq.pop(); // 그 강의를 pop
            pq.push(lesson[i].second); // 이제 현재 강의의 끝나는 시간으로 대체
        }
    }

    cout << pq.size(); // 강의실의 수 == pq의 사이즈
}