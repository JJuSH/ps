#include<iostream>
#include<stdio.h>
#include<string.h>
int dp[1001];
int arr[1001];
int N, max_;
int main(){
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d", &arr[i]);
    }
    
    memset(dp, 0 , sizeof(dp));
    dp[1] = arr[1];
    max_ = dp[1];
    
    for(int i = 2 ; i <= N ; i++){
        dp[i] = arr[i];
        for(int j = 1 ; j <= i ; j++){
            if(arr[j] < arr[i]){
                dp[i] = std::max(dp[i], dp[j] + arr[i]);
            }
        }
        max_ = std::max(max_ , dp[i]);
    }
    //for(int i = 1 ; i <= N ; i++){
    //    printf("%d ", dp[i]);
    //}
    
    printf("%d\n", max_);
    return 0;
}

