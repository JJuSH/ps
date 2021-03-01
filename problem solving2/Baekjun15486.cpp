#include<stdio.h>
#include<iostream>
#define INF 987654321

int dp[1500100];
int day[1500100];
int val[1500100];
int N;

int max_val(int from){
    if(from > N + 1) return dp[from] = -INF;
    else if(from == N + 1) return dp[from] = 0;
    else{
        if(dp[from] != -1) return dp[from];
        else{
            dp[from] = std::max(max_val(from + day[from]) + val[from] , max_val(from + 1));
            return dp[from];
        }
    }
}

int main(){
    std::cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int T, V;
        std::cin >> T >> V;
        day[i] = T;
        val[i] = V;
    }
    for(int i = 1 ; i <= N ; i++) dp[i] = -1;
    max_val(1);
    //for(int i = 1 ; i <= N ; i++) std::cout << dp[i] << " ";
    std::cout << dp[1] << "\n";
    return 0;
}
