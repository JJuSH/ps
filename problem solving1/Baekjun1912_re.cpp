#include<iostream>
#include<stdio.h>
int N, max_;
int arr[100001];
int dp[100001];

int main(){
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[1];
    max_ = dp[1];
    for(int i = 2 ; i <= N ; i++){
        dp[i] = std::max(dp[i-1] + arr[i] , arr[i]);
        max_ = std::max(max_ , dp[i]);
    }
    printf("%d\n", max_);
    return 0;
}
