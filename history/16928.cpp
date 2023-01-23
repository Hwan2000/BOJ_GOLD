#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

unordered_map<int,int> Map;
int N,M;
int arr[101];

int main() {
    cin >> N >> M;
    int x;int y;
    for(int n=0;n<N;n++){
        cin >> x >> y;
        Map.insert({x,y});
    }
    for(int m=0;m<M;m++){
        cin >> x >> y;
        Map.insert({x,y});
    }

    queue<int> Q; Q.push(1); arr[1] = 1;

    while(arr[100] == 0){
        int now = Q.front(); Q.pop();

        for(int i=1;i<=6;i++){
            int next = now + i;

            if(next > 101) continue;

            if(Map.find(next) != Map.end()){
                next = Map.find(next)->second;
            }

            if(arr[next] == 0){
                arr[next] = arr[now] + 1;
                Q.push(next);
            }
        }
    }

    cout << arr[100] - 1;
}
