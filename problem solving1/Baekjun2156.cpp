#include<iostream>
int wine[10000] = {0};
long int amount[10000];

void drink(int N){
  for(int i = 2 ; i < N ; i++){
    amount[i] = std::max(amount[i-1], std::max(amount[i-2] + wine[i], amount[i-3] + wine[i-1] + wine[i]));
  }
  return;
}


int main(){
  int N;
  std::cin >> N;
  for(int i = 0; i < N ; i++){
    std::cin >> wine[i];
  }
  if(N == 1) std::cout << wine[0];
  else if(N == 2) std::cout << wine[0] + wine[1];
  else{
    amount[0] = wine[0];
    amount[1] = wine[0] + wine[1];

    drink(N);

    std::cout << amount[N-1];
  }
  return 0;
}
