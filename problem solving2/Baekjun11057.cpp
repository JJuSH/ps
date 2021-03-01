#include<iostream>
long long int dp[1001][10];
int N;

int main(){
    std::cin >> N;
    for(int i = 0 ; i < 10 ; i++){
        dp[1][i] = 1;
    }
    for(int i = 2 ; i <= N ; i++){
        for(int j = 0 ; j < 10 ; j++){
            long long int sum = 0 ;
            int k = j;
            while(k >= 0){
                sum += dp[i-1][k];
                k--;
            }
            dp[i][j] = sum % 10007;
        }
    }
    long long int ans = 0;
    for(int i = 0 ; i < 10 ; i++){
        ans += dp[N][i];
    }
    std::cout << ans % 10007 << "\n";
    return 0;
}
