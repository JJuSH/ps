#include<iostream>
int N;
int loc_max = 0;


int arr[200];
int dp[200] = {0};
int max_ = 1;
void lis(){
    dp[0] = 1;
    for(int i = 1 ; i < N ; i++){
        dp[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_ = std::max(max_, dp[i]);
    }
}
int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) std::cin >> arr[i];
    lis();
    
    std::cout << N - max_ << "\n";
    
    return 0;
}
