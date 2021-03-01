#include<iostream>

long long int wire[10000];
long long int min = 1;
long long int high = 0;
long long int K, N;

long long int num_wire(int length){
  long long int count = 0;
  for(int i = 0 ; i < K ; i++){
    long long int temp = wire[i] / length;
    count = count + temp;
  }
  //std::cout << "num_wire_call" << length << " " << count << "\n";
  return count;
}
long long int find(long long int start, long long int end, long long int num){
  //std::cout << "find_call" << start << " " << end << " " << num << "\n";
  long long int result = 0;
  while(start <= end){
  long long int mid = (start + end)/2;
  long long int wire_num = num_wire(mid);

    if(wire_num < num){
      end = mid-1;
    }
    else if(wire_num >= num){
      start = mid + 1;
    }
  }
  return end;
}
int main(){

  std::cin >> K >> N;

  for(int i = 0 ; i < K ; i++){
    std::cin >> wire[i];
    high = std::max(wire[i],high);
  }

  std::cout << find(1,high,N);
  return 0;
}
