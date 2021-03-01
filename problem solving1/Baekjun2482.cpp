#include<iostream>
#define MOD 1000000003
int dp[1001][1001];
int N, K;

int find(int n , int k){
    if(k == 0) return dp[n][k] = 0;
    else if(k == 1) return dp[n][k] = n;
    else if( k > (n / 2)) return dp[n][k] = 0;
    else{
        if(dp[n][k] != -1 ) return dp[n][k];
        else{
            dp[n][k] = (find(n-2, k-1) + find(n-1, k)) % MOD;
            return dp[n][k];
        }
    }
}

int main(){
    std::cin >> N >> K;
    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            dp[i][j] = -1;
        }
    }
    std::cout << find(N,K) << "\n";
    return 0;
}
