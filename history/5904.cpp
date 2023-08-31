//5904: Moo 게임
//https://www.acmicpc.net/problem/5904
#include<iostream>

using namespace std;

char answer;

int arr[1000];

int N;

//x는 arr인덱스 y는 세부 인덱스
void recursive(int x, int y) {

    if(x==1){
        if(y==1){
            answer = 'm';
            return;
        } else {
            answer = 'o';
            return;
        }
    }

    if(y <= arr[x-1]){
        recursive(x-1,y);
    } else if( y > arr[x-1] + x + 2){
        recursive(x-1,y-arr[x-1]-x-2);
    } else {
        if(y-arr[x-1]==1){
            answer = 'm';
            return;
        } else {
            answer = 'o';
            return;
        }
    }
}

int main(){
    cin >> N;
    arr[1] = 3;

    int count = 1;

    while(N > arr[count]){
        arr[count+1] = arr[count]*2 + count+3;
        count += 1;
    }
    //cout << count;
    recursive(count, N);

    cout << answer;
}