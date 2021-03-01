#include<iostream>
#define INF 1000000000
int N;
long long int dp[101][10];

int main(){
    std::cin >> N;
    for(int i = 1 ; i < 10 ; i++){
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
    
    for(int i = 2 ; i <= N ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(j == 0) dp[i][j] = dp[i-1][j+1] % INF;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % INF;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % INF;
        }
    }
    long long int sum = 0;
    for(int i = 0 ; i < 10 ; i++){
        sum = sum + dp[N][i];
    }
    std::cout << sum % INF << "\n";
    return 0;
}
