#include<iostream>
#include<vector>

int main(){
  std::vector<int> v;
  int N;
  std::cin >> N;
  for(int i = 0; i < N ; i++){
    int temp;
    std::cin >> temp;
    if(temp == 0){
      v.pop_back();
    }
    else{
      v.push_back(temp);
    }
  }
  int sum = 0;
  for(int i = 0; i < v.size() ; i++){
    sum = sum + v[i];
  }
  std::cout << sum ;
  return 0;
}
