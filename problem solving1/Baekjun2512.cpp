#include<iostream>
#include<stdio.h>

int N, M;
long long int budget[10000];
long long int local_max = 0;
int find(int limit){
    long long int sum = 0;
    for(int i = 0 ; i < N ; i++){
        if(budget[i] > limit) sum += limit;
        else sum += budget[i];
    }
    return sum;
}
int binary_search(int start, int end, int target){
    int result = 1;
    while(start <= end){
        int mid = (start + end) / 2;
        int cur_sum = find(mid);
        //std::cout << "while " << start << " " << end << " " << cur_sum << "\n";
        if(cur_sum <= target){
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return result;
}
int main(){
    scanf("%d" , &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &budget[i]);
        local_max = std::max(local_max, budget[i]);
    }
    scanf("%d" , &M);
    printf("%d\n", binary_search(0 , local_max, M));
    return 0;
}
