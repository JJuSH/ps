#include<iostream>
int dp[1001];
int N;

int main(){
    std::cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= N ; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    std::cout << dp[N] << "\n";
}
