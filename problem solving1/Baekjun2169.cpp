#include<iostream>
#define INF 987654321
int field[1001][1001];
int dp[1002][1002];
int right[1002];
int left[1002];
int N, M;



int main(){
    scanf("%d %d" , &N, &M);
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            scanf("%d", &field[i][j]);
            dp[i][j] = -INF;
        }
    }
    dp[1][1] = field[1][1];
    for(int i = 2 ; i <= M ; i++){
        dp[1][i] = dp[1][i-1] + field[1][i];
    }

    for(int i = 2 ; i <= N ; i++){
        left[0] = -INF;
        for(int j = 1 ; j <= M ; j++){
            left[j] = std::max(dp[i-1][j], left[j-1]) + field[i][j];
        }
        right[M + 1] = -INF;
        for(int j = M ; j >= 1 ; j--){
            right[j] = std::max(dp[i-1][j], right[j + 1]) + field[i][j];
        }
        for(int j = 1 ; j <= M ; j++){
            dp[i][j] = std::max(left[j], right[j]);
        }
    }
    std::cout << dp[N][M] << "\n";
    return 0;
}
