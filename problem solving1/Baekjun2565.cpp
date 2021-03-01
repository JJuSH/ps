#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

int main(){
  int N;
  std::cin >> N;
  std::vector<std::pair<int,int>> p;
  std::vector<int> length;
  for(int i = 0 ; i < N ; i++){
    int a ,b;
    std::cin >> a >> b ;
    p.push_back({b,a});
    length.push_back(1);
  }
  std::sort(p.begin(), p.end());
  int max = 1;
  for(int i = 1 ; i < N ; i++){
    for(int j = 0 ; j < i ; j++){
      if(p[i].second > p[j].second){
        length[i] = std::max(length[i], length[j] + 1);
      }
    }
    max = std::max(max, length[i]);
  }
  std::cout << N-max;
  return 0;
}
