#include<iostream>
#include<stdio.h>
#include<string.h>
int dp[30][30];
int test_case;
int N, M;
void print_(){
    for(int j = 0 ; j <= N ; j++){
        for(int k = 0 ; k <= M ; k++){
            printf("%d ", dp[j][k]);
        }
        printf("\n");
    }
}
int main(){
    scanf("%d", &test_case);
    for(int i = 0 ; i < test_case ; i++){
        scanf("%d %d", &N, &M);
        for(int j = 0 ; j <= N ; j++) dp[j][0] = 0;
        for(int j = 0 ; j <= M ; j++) dp[0][j] = 0;
        
        dp[1][1] = 1;
        
        for(int j = 1 ; j <= N ; j++){
            for(int k = 1 ; k <= M ; k++){
                if(j == 1 && k == 1) continue;
                dp[j][k] = j*dp[j-1][k] + k*dp[j][k-1];
            }
        }
        print_();
    }
    return 0;
}
