#include<iostream>
#include<stdio.h>
int dp[31];
int N;

int main(){
    scanf("%d" , &N);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    for(int i = 5 ; i <= N ; i++){
        dp[i] = dp[i-2] * 3;
        for(int j = i - 4 ; j >= 0 ; j = j-2){
            dp[i] += 2 * dp[j];
        }
    }
    printf("%d\n", dp[N]);
    return 0;
}
