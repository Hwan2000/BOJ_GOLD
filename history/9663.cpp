//N-Queen

#include<iostream>

using namespace std;

int N = 4;

int answer = 0;

int X[16]={0,0,0,0,0};
int Y[16]={0,0,0,0,0};

bool checkout(int x, int y){
  for(int i=1; i<x; i++){
    if(Y[i] == y || (x - X[i]) == (y - Y[i]) || (x - X[i]) == (Y[i] - y)){
      return false;
    }
  }
  return true;
}


void nQueen(int maxnum){
  if(maxnum == N+1){
    //cout << "Success: ";
    answer += 1;
    // for(int i=1; i<=N; i++){
    //   cout << "(" << X[i] << "," << Y[i] << ") ";
    // }
    //cout << '\n';
    return;
  } else {
    for(int i=1; i<=N; i++){
      if(checkout(maxnum,i)){
        X[maxnum] = maxnum;
        Y[maxnum] = i;
        nQueen(maxnum+1);
        X[maxnum] = 0;
        Y[maxnum] = 0;
      }
    }
  }
}

int main(){
  cin >> N;
  nQueen(1);
  cout << answer;
  return 0;
}