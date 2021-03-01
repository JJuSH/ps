#include<iostream>
#include<stdio.h>
#include<algorithm>
int N, M;
int lesson[100000];
int find_num_disk(long long int lim){
    long long int cur_sum = 0;
    int num_disk = 1;
    
    for(int i = 0 ; i < N ; i++){
        if(lesson[i] <= lim - cur_sum) cur_sum += lesson[i];
        else{
            num_disk++;
            cur_sum = lesson[i];
        }
    }
    return num_disk;
}

long long int bs(long long int start, long long int end, int target){
    long long int result = start;
    while(start <= end){
        long long int mid = (start + end) / 2;
        int num_disk = find_num_disk(mid);
        if(num_disk <= target){
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return start;
}

int main(){
    scanf("%d %d", &N , &M);
    long long int tot_sum = 0;
    int loc_max = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &lesson[i]);
        tot_sum += lesson[i];
        loc_max = std::max(loc_max , lesson[i]);
    }
    printf("%lld\n",  bs(loc_max , tot_sum, M));
    return 0;
}
