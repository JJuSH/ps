#include<iostream>
#include<stdlib.h>
#include<utility>
#include<vector>
int N;
int case_num;
int dp[1001][6] = {0,};
std::vector<std::pair<int, int> > acc;


int main(){
    std::cin >> N >> case_num;
    dp[0][2] = 1;
    dp[0][3] = 1;
    dp[0][4] = N;
    dp[0][5] = N;
    
    for(int i = 0 ; i < case_num ; i++){
        int a, b;
        std::cin >> a >> b;
        acc.push_back(std::make_pair(a,b));
    }
    
    
    return 0;
}
