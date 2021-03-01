#include<iostream>
int dp[1000][3];
int house[1000][3];
int N;

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        int r, g, b;
        std::cin >> r >> g >> b;
        house[i][0] = r;
        house[i][1] = g;
        house[i][2] = b;
    }
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < 3 ; j++){
            dp[i][0] = std::min(dp[i-1][1], dp[i-1][2]) + house[i][0];
            dp[i][1] = std::min(dp[i-1][0], dp[i-1][2]) + house[i][1];
            dp[i][2] = std::min(dp[i-1][0], dp[i-1][1]) + house[i][2];
        }
    }
    int min = std::min(dp[N-1][0], std::min(dp[N-1][1] , dp[N-1][2]));
    std::cout << min << "\n";
    return 0;
}
