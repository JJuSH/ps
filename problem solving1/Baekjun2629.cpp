#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int choo[31];
int test_case[8];
int num_choo, num_test;
bool dp[31][15001] = {false, };
bool weight[15001] = {false, };
void make_weight(int current_choo, int current_weight){

  if(current_choo > num_choo) return;
  if(dp[current_choo][current_weight] != false){
    return;
  }
  //printf("make_weight_call %d - %d\n", current_choo, current_weight);
  dp[current_choo][current_weight] = true;
  weight[current_weight] = true;
  make_weight(current_choo + 1, current_weight + choo[current_choo+1]);
  make_weight(current_choo + 1, current_weight);
  make_weight(current_choo + 1, abs(current_weight - choo[current_choo+1]));

}


int main(){
  scanf("%d",&num_choo);
  for(int i = 1 ; i <= num_choo ; i++){
    scanf("%d",&choo[i]);
  }
  scanf("%d",&num_test);
  for(int i = 1 ; i <= num_test ; i++){
    scanf("%d",&test_case[i]);
  }

  make_weight(0,0);
  for(int i = 1 ; i <= num_test ; i++){
    if(weight[test_case[i]]){
      printf("Y\n");
    }
    else printf("N\n");
  }

  return 0;
}
