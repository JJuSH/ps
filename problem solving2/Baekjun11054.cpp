#include<iostream>
int series[1000];
int increase[1000];
int decrease[1000];

void increase_func(int N){
  for(int i = 1 ; i < N ; i++){
    increase[i] = 1;
    for(int j = 0 ; j < i ; j++){
      if(series[i] > series[j]){
        increase[i] = std::max(increase[i], increase[j] + 1);
      }
    }
  }
}

void decrease_func(int N){
  for(int i = N-2 ; i > 0 ; i--){
    decrease[i] = 1;
    for(int j = N-1 ; j > i ; j--){
      if(series[i] > series[j]){
        decrease[i] = std::max(decrease[i], decrease[j] + 1);
      }
    }
  }
}

int main(){
  int N;
  std::cin >> N;
  for(int i = 0; i < N ; i++){
    std::cin >> series[i];
  }
  increase[0] = 1;
  decrease[N-1] = 1;
  increase_func(N);
  decrease_func(N);
  int max = 0;
  for(int i = 0 ; i < N ; i++){
    max = std::max(max , increase[i] + decrease[i] - 1);
  }
  std::cout << max ;

  return 0;
}
