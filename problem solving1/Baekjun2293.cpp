#include<iostream>
int dp[10001];
int coin[101];
int N,K;
int main(){
  std::cin >> N >> K;

  for(int i = 1 ; i <= N ; i++){
    std::cin >> coin[i];
  }
  dp[0] = 1;
  for(int i = 1 ; i <= N ; i++){
    for(int j = coin[i] ; j <= 10000 ; j++){
      dp[j] = dp[j] + dp[j-coin[i]];
    }
  }
  std::cout << dp[K];
  return 0;
}
