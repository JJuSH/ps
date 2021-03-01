#include<iostream>

long long int N, K;
long long int result;
long long int count_less(long long int n){
  long long int count = 0;
  long long int maximum = 0;
  for(long long int i = 1 ; i <= N ; i++){
    count += std::min(N, n/i);
  }
  return count;
}
int main(){
  std::cin >> N >> K;

  long long int start = 1;
  long long int end = N*N;
  result = N*N;
  while(start <= end){
    long long int mid = (start + end) / 2;
    long long int under_mid = count_less(mid);
    //std::cout << start << " " << end << " " << under_mid << "\n";
    if(under_mid < K){
      start = mid + 1;
    }
    else{
      result = mid;
      end = mid - 1;

    }

  }
  std::cout << result;
  return 0;
}
