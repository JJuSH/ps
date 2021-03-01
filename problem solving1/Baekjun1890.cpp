#include<iostream>
int N;
int field[100][100] = {0};
long long int dp[100][100];
int main(){
    std::cin >> N ;
    for(int i  = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> field[i][j];
        }
    }
    
    for(int i  = N-1 ; i >=0 ; i--){
        for(int j = N-1 ; j >= 0 ; j--){
            if(i == N - 1 && j == N - 1) continue;
            
            if(i + field[i][j] == N - 1 && j == N - 1){
                dp[i][j]++;
            }
            if(j + field[i][j] == N - 1 && i == N - 1){
                dp[i][j]++;
            }
            if(i + field[i][j] <= N - 1){
                dp[i][j] += dp[i + field[i][j]][j];
            }
            if(j + field[i][j] <= N-1){
                dp[i][j] += dp[i][j + field[i][j]];
            }
        }
    }
    /*
    for(int i  = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }
     */
    std::cout << dp[0][0] << "\n";
    return 0;
}
