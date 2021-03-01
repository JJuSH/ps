#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

int main(void){
  int N;
  std::vector<std::pair<int,int>> p;
  std::cin >> N;
  for(int i = 0; i < N ; i++){
    int a;
    int b;
    std::cin >> a >> b ;
    p.push_back({b,a});
  }
  std::sort(p.begin(), p.end());
  int count = 0;
  int current_start = 0;
  int current_end = 0;
  for(int i = 0; i < p.size() ; i++){f
    if(current_end <= p[i].second){
      current_end = p[i].first;
      current_start = p[i].second;
      count++;
    }
  }
  std::cout << count << std::endl;
  return 0;
}
