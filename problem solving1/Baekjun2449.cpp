#include<iostream>
#define INF 987654321
int N, K;
int light[201];
int dp[201][201];

int find_num(int start, int end){
    if(dp[start][end] != -1) return dp[start][end];
    else{
        if(start == end) return dp[start][end] = 0;
        else{
            dp[start][end] = INF;
            for(int i = start ; i < end ; i++){
                int f = find_num(start, i);
                int b = find_num(i + 1, end);
                int temp = (light[start] == light[i + 1]) ? 0 : 1 ;
                dp[start][end] = std::min(dp[start][end], f + b + temp);
            }
            return dp[start][end];
        }
    }
}

int main(){
    std::cin >> N >> K;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        if (i == 0) light[idx++] = x;
        else if(x != light[idx-1]) light[idx++] = x;
    }

    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            dp[i][j] = -1;
        }
    }
    std::cout << find_num(0 , idx - 1) << "\n";
    return 0;
}
