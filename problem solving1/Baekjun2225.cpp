#include<iostream>
#define INF 1000000000
int N, K;
int dp[201][201];

int find_ans(int n, int k){
    if(dp[n][k] != 0) return dp[n][k];
    else{
        if(n == 0) return dp[n][k] = 1;
        if(k == 1) return dp[n][k] = 1;
        else if(k == 2) return dp[n][k] = n + 1;
        else{
            dp[n][k] = 0;
            for(int i = 0 ; i <= n ; i++){
                dp[n][k] = (dp[n][k] + find_ans(i,k - 1)) % INF;
            }
            return dp[n][k];
        }
    }
}
int main(){
    std::cin >> N >> K;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            dp[i][j] = 0;
        }
    }
    std::cout << find_ans(N,K) << "\n";
    return 0;
}
