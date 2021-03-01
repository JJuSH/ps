#include<iostream>
#define F 987654321
int dp[101][10001];
int coin[101];
int N, target;

int main(){
    std::cin >> N >> target;
    for(int i = 1 ; i <= N ; i++){
        std::cin >> coin[i];
    }
    for(int i = 0 ; i <= N ; i++){
        dp[i][0] = F;
    }
    for(int i = 0 ; i <= target ; i++){
        dp[0][i] = F;
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= target ; j++){
            if(coin[i] > j){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            else{
                int num = 0;
                if(j - coin[i] == 0) dp[i][j] = 1;
                else dp[i][j] = std::min(dp[i-1][j] , dp[i][j - coin[i]] + 1);
                
            }
        }
    }
    /*
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= target ; j++){
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    */
    if(dp[N][target] == F) std::cout << -1 << "\n";
    else std::cout << dp[N][target] << "\n";
    return 0;
}
