#include<iostream>
#include <stdio.h>
#include <stdlib.h>
long long int num,times,divider;
long long int multiplier(long long int num, long long int times){

  if(times == 1){
    return num % divider;
  }
  else{

    if((times % 2) == 0){
      long long int half = multiplier(num, times/2);
      half = (half*half) % divider;
      return half;
    }
    else{
      long long int half = multiplier(num, (times-1)/2);
      half = (half*half) % divider;
      return (half * num) % divider;
    }
  }
}

int main(){

  std::cin >> num >> times >> divider;
  std::cout << multiplier(num % divider, times) % divider;

  return 0;
}
