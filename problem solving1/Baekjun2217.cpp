#include<iostream>
#include<stdio.h>
#include<algorithm>
int N;
long long int rope[100000];
int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &rope[i]);
    }
    
    std::sort(rope, rope + N);
    
    long long int max_weight = 0;
    for(int i = 0 ; i < N ; i++){
        max_weight = std::max(max_weight, rope[i] * (N - i));
    }
    std::cout << max_weight << "\n";
    return 0;
}
