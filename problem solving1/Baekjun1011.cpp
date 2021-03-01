#include<iostream>
#include<vector>

int main(){
  long long int N;
  std::cin >> N;
  std::vector<int> v;
  for(int i = 0 ; i < N ; i++){
    long long int start, finish;
    std::cin >> start >> finish;

    long long int distance = finish - start;

    long long int step = 1;

    if(distance == 1) step = 1;
    else{
      while(true){
        long long int max_distance = (step-1) * (step-1);
        if(distance > max_distance) step++;
        else break;
      }
    }
    v.push_back(step);
  }
  for(int i = 0 ; i < v.size() ; i++){
    std::cout << v[i] << "\n";
  }

  return 0;
}
