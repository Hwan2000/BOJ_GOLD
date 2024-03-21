//6198: 옥상 정원 꾸미기
//https://www.acmicpc.net/problem/6198
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

stack<pair<int, int>> S;
int N;
long long answer_sum = 0;
int x;

int main(){

    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> x;
        if(S.empty() || S.top().first > x){
            S.push({x,i}); //스택이 비거나 top에서 현재의 건물을 볼 수 있으면 삽입
        } else if(S.top().first <= x){
            while(1){
                if(S.empty() || S.top().first > x){
                    S.push({x,i});
                    break; // 위의 조건이 되면 스택에 삽입하고 break;
                }
                answer_sum += i-S.top().second-1; // top보다 크거나 같은 건물이 있으면 해당 건물은 더 이상 아무것도 볼 수 없다.
                S.pop(); // 따라서 현재 건물의 번호 - top 건물의 번호 - 1이 top 건물에서 볼 수 있는 옥상의 개수다.
            }
        }
    }

    int top_of_stack = S.top().second; // 스택에 남은 건물들은 스택에서 자신의 위에 있는 건물들을 전부 볼 수 있다.
    S.pop();

    while(!S.empty()){
        answer_sum += top_of_stack-S.top().second; // 스택에 남은 건물들이 볼 수 있는 건물 수 계산
        S.pop();
    }

    cout << answer_sum;
}