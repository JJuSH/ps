#include<iostream>
#include<string>
#define INF 987654321
int dp[2501][2501] = {0};
int count[2501];
std::string s;

int main(){
    std::cin >> s;
    
    int n = s.size();
    s = " " + s;
    
    for(int i = 1 ; i <= n ; i++){
        dp[i][i] = 1;
        if(i + 1 != n + 1 && s[i] == s[i + 1]){
            dp[i][i + 1] = 1;
        }
    }
    for(int k = 2 ; k < n ; k++){
        for(int i = 1 ; i <= n - k ; i++){
            int j = i + k;
            
            if(s[i] == s[j] && dp[i + 1][j - 1] == 1) dp[i][j] = 1;
        }
    }
    count[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        count[i] = INF;
        for(int j = 1 ; j <= i ; j++){
            if(dp[j][i]) count[i] = std::min(count[j - 1] + 1 , count[i]);
        }
    }
    std::cout << count[n] << "\n";
    return 0;
}
