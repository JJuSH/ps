#include<iostream>
#include<string>
int N, M, on_count;
int cost[16][16];
bool on_off[16] = false;
int dp[16][16];
int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> cost[i][j];
        }
    }
    std::string s;
    std::cin >> s;
    on_count = 0;
    for(int a = 0 ; s < s.length() ; s++){
        if(s[a] == 'Y'){
            on_off[a] = true;
            on_count++;
        }
        else on_off[a] = false;
    }
    std::cin >> M;
    
    
    return 0;
}
