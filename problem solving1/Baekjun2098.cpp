#include<iostream>
#include<string.h>
#define INF 987654321
int cost[16][16];
int N, ans_bit;
int dp[16][1 << 16];

int dfs(int cur_node, int record){
    if(record == ans_bit){
        if(cost[cur_node][0] == 0) return INF;
        else return cost[cur_node][0];
    }
    if(dp[cur_node][record] != -1) return dp[cur_node][record];
    else{
        dp[cur_node][record] = INF;
        for(int i = 0 ; i < N ; i++){
            if((cost[cur_node][i] == 0) || ((record & (1 << i)) == (1 << i))) continue;
            else dp[cur_node][record] = std::min(dp[cur_node][record], dfs(i, record + (1 << i)) + cost[cur_node][i]);
        }
        return dp[cur_node][record];
    }
}

int main(){
    std::cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> cost[i][j];
        }
    }
    ans_bit = (1 << N) - 1;
    std::cout << dfs(0,1) << "\n";
    return 0;
}
