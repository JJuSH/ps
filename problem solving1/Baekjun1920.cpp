#include<iostream>

int series[100000];
int sort[100000];
int query[100000];
void merge(int start1, int end1, int start2, int end2){
  int flag1 = start1;
  int flag2 = start2;

  int count = start1;
  while((flag1 <= end1) && (flag2 <= end2)){
    if(series[flag1] > series[flag2]){
      sort[count] = series[flag2];
      flag2++;
      count++;
    }
    else{
      sort[count] = series[flag1];
      flag1++;
      count++;
    }
  }
  if(flag1 > end1){
    for(int i = flag2 ; i <= end2; i++){
      sort[count] = series[i];
      count++;
    }
  }
  else{
    for(int i = flag1 ; i <= end1; i++){
      sort[count] = series[i];
      count++;
    }
  }

  for(int i = start1 ; i <= end2 ; i++){
    series[i] = sort[i];
  }

  return;
}

void merge_sort(int start, int end){
  if(end > start){
    int mid = (end + start)/2 ;
    merge_sort(start, mid);
    merge_sort(mid+1, end);
    merge(start, mid, mid+1, end);
  }
  else if(start == end){
    return;
  }
  return;
}
bool find(int start, int end, int f){
  std::cout << "start_call" << start << " " << end << " " << f << "\n";
  int mid = (start + end)/2;
  if(start == end){
    if(f == series[start]) return true;
    else return false;
  }
  else{
    if(f > series[mid]){
      return find(mid+1, end, f);
    }
    else if(f < series[mid]){
      return find(start, mid, f);
    }
    else{
      return true;
    }
  }
}
int main(){
  int N ;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    std::cin >> series[i];
  }
  merge_sort(0,N-1);
  int M;
  std::cin >> M;
  for(int i = 0 ; i < M ; i++){
    std::cin >> query[i];
    if(find(0, N-1, query[i])) query[i] = 1;
    else query[i] = 0;
  }
  for(int i = 0 ; i < M ; i++){
    std::cout << query[i] << "\n";
  }
  return 0;
}
