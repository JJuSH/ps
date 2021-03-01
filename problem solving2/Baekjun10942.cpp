#include<iostream>
#include<string.h>
int palin[2000][2000];
int series[2000];
int check_palin(int start, int end){
  if(palin[start][end] != 0x3f3f3f3f){
    return palin[start][end];
  }
  else{
    if(start == end){
      palin[start][end] = 1;
      return palin[start][end];
    }
    else if(start + 1 == end){
      if(series[start] == series[end]){
        palin[start][end] = 1;
        return palin[start][end];
      }
      else{
        palin[start][end] = 0;
        return palin[start][end];
      }
    }
    else{
      int smaller = check_palin(start + 1, end-1);
      if((series[start] == series[end]) && smaller){
        palin[start][end] = 1;
        return palin[start][end];
      }
      else{
        palin[start][end] = 0;
        return palin[start][end];
      }
    }
  }
}

int main(){
  int N;
  scanf("%d", &N);
  memset(palin, 0x3f, sizeof(palin));
  for(int i = 0 ; i < N ; i++){
     scanf("%d", &series[i]);
  }

  int Q;
  scanf("%d", &Q);
  for(int i = 0 ; i < Q ; i++){
    int start,end;
    scanf("%d %d", &start, &end);
    printf("%d\n", check_palin(start-1, end-1));
  }
  return 0;
}
