#include<iostream>
int N;
int dp[1000001] = {0};
int ans = 0;
int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        int a;
        std::cin >> a;
        dp[a] = dp[a-1] + 1;
        ans = std::max(dp[a], ans);
    }
    std::cout << N - ans << "\n";
    return 0;
}
