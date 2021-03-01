#include<iostream>
#include<algorithm>
long long int series[100000];
long long int dp[100000];
int main(){
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    std::cin >> series[i] ;
  }
  dp[0] = series[0];
  int maxi = dp[0];
  for(int i = 1 ; i < N ; i++){
    dp[i] = std::max(dp[i-1] + series[i] , series[i]);
    if(dp[i] > maxi) maxi = dp[i];
  }
  std::cout << maxi;
  return 0;
}
