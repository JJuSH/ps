#include<iostream>
int T, W;
int dp[1001][31] = {0};
int apple[1001];
int main(){
    std::cin >> T >> W;
    for(int i = 1 ; i <= T ; i++){
        std::cin >> apple[i];
    }
    if(apple[1] == 1){
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else{
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
    
    for(int i = 2 ; i <= T ; i++){
        if(apple[i] == 1) dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = dp[i-1][0];
        
        for(int j = 1 ; j <= std::min(i + 3 , W) ; j++){
            if(apple[i] == 1){
                if(j % 2 == 0){
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-1]) + 1;
                }
                else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-1]);
                }
            }
            else{
                if(j % 2 == 0){
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-1]) + 1;
                }
            }
        }
    }
    /*
    for(int i = 0 ; i <= T ; i++){
        for(int j = 0 ; j <= W ; j++){
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
    */
    int max_ = 0;
    for(int i = 0 ; i <= W ; i++){
        max_ = std::max(max_ , dp[T][i]);
    }
    std::cout << max_ << "\n";
    return 0;
}
