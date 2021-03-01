#include<iostream>
int stairs[300];
long int point[300][2];

void walk(int N){
  for(int i = 2; i < N ; i++){
    point[i][0] = std::max(point[i-2][0] + stairs[i],point[i-2][1] + stairs[i]);
    point[i][1] = point[i-1][0] + stairs[i];
  }
  return;
}

int main(){
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    std::cin >> stairs[i];
  }
  if(N == 1){
    std::cout << stairs[0];
  }
  else if(N == 2){
    std::cout << stairs[0] + stairs[1];
  }
  else{
    point[0][0] = stairs[0];
    point[0][1] = stairs[0];
    point[1][0] = stairs[1];
    point[1][1] = stairs[0] + stairs[1];
    walk(N);
    int maximum = std::max(point[N-1][0], point[N-1][1]);
    std::cout << maximum ;
  }

  return 0;
}
