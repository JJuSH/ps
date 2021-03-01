#include<iostream>
#define INF 987654321
int dp[100][100][50];
int dp_one[100];
int seq[100];
int N, M;
int find_one(int start, int end){
    dp_one[start] = seq[start];
    if(start == end) return seq[start];
    for(int i = start + 1; i <= end ; i++){
        dp_one[i] = std::max(dp_one[i-1] + seq[i] , seq[i]);
    }
    return dp_one[end];
}

int find(int start, int end, int m){
    if(dp[start][end][m] != -1) return dp[start][end][m];
    else{
        if(m == 1) return dp[start][end][m] = find_one(start,end);
        if(end - start < 2 * m) return dp[start][end][m] = -INF;
        else{
            for(int i = start + 1 ; i < end - 1 ; i++){
                dp[start][end][m] = std::max(find(start, i - 1, m - 1) + find(i + 1, end, 1), dp[start][end][m]);
            }
            return dp[start][end][m];
        }
    }
}
int main(){
    std::cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        std::cin >> seq[i];
    }
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            for(int k = 0 ; i < 50 ; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    std::cout << find(0 , N - 1 , M) << "\n";
    return 0;
}
