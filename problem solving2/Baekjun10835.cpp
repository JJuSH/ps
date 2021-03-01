#include<iostream>
int N;
int dp[2000][2000]; // i , j 번째까지 카드로 시작할 때 얻을 수 있는 최대 점수 i: left, j: right
int left[2000];
int right[2000];
int main(){
    std::cin >> N;
    for(int i = N-1 ; i >= 0 ; i--) std::cin >> left[i];
    for(int i = N-1 ; i >= 0 ; i--) std::cin >> right[i];
    dp[0][0] = (left[0] > right[0]) ? right[0] : 0;
    for(int i = 1 ; i < N; i++){
        dp[i][0] = (left[i] > right[0]) ? right[0] : dp[i-1][0];
        dp[0][i] = (left[0] > right[i]) ? right[i] + dp[0][i-1] : dp[0][i-1];
    }
    dp[0][0] = (left[0] > right[0]) ? right[0] : 0;
    for(int i = 1 ; i < N ; i++){
        for(int j = 1 ; j < N ; j++){
            if(left[i] > right[j]) dp[i][j] = std::max(dp[i-1][j-1], dp[i][j-1] + right[j]);
            else dp[i][j] = std::max(dp[i-1][j-1] , dp[i-1][j]);
        }
    }
    std::cout << dp[N-1][N-1] << "\n";
    return 0;
}
