#include<iostream>
long long int dp[91][2];
int N;

int main(){
    std::cin >> N;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 0;
    for(int i = 3 ; i <= N ; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    std::cout << dp[N][0] + dp[N][1] << "\n";
    return 0;
}
