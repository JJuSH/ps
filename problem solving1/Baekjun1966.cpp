#include<iostream>
#include<queue>
#include<utility>
#include<vector>

int case_num,N, Q;
int result[100];

int main(){
  std::cin >> case_num;
  for(int k = 0 ; k < case_num ; k++){
    std::cin >> N >> Q;
    std::vector<std::pair<int,int>> v;
    for(int i = 0 ; i < N ; i++){
      int this_one = 0;
      if(Q == i) this_one = 1;
      int temp;
      std::cin >> temp;
      v.push_back({temp,this_one});
    }
    int count = 0;
    while(true){
      int this_prior = v.front().first;
      bool ok = true;
      for(int i = 0 ; i < v.size() ; i++){
        if(this_prior < v[i].first) ok = false;
      }
      if(ok){
        if(v.front().second == 1){
          count++;
          break;
        }
        else{
          v.erase(v.begin());
          count++;
        }
      }
      else{
        v.push_back(v.front());
        v.erase(v.begin());
      }
    }
    result[k] = count;
  }
  for(int i = 0 ; i < case_num ; i++){
    std::cout << result[i] << "\n";
  }
  return 0;
}
