#include<iostream>
#include<stdio.h>
int N;
int LDS[100001];
int LIS[100001];
int cur_len_i = 1;
int cur_len_d = 1;
int max_len_i = 1;
int max_len_d = 1;
int main(){
    scanf("%d", &N);
    int cur_num;
    int prev_num;
    scanf("%d", &cur_num);
    cur_len_i = 1;
    cur_len_d = 1;
    prev_num = cur_num;
    
    for(int i = 1 ; i < N ; i++){
        scanf("%d", &cur_num);
        if(cur_num > prev_num){
            cur_len_i++;
            max_len_i = std::max(max_len_i , cur_len_i);
            max_len_d = std::max(max_len_d , cur_len_d);
            cur_len_d = 1;
        }
        else if(cur_num < prev_num){
            cur_len_d++;
            max_len_i = std::max(max_len_i , cur_len_i);
            max_len_d = std::max(max_len_d , cur_len_d);
            cur_len_i = 1;
        }
        else{
            cur_len_i++;
            cur_len_d++;
            max_len_i = std::max(max_len_i , cur_len_i);
            max_len_d = std::max(max_len_d , cur_len_d);
        }
        prev_num = cur_num;
    }
    std::cout << std::max(max_len_d, max_len_i) << "\n";
    return 0;
}
