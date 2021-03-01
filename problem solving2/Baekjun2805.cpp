#include<iostream>
#include<vector>
std::vector<int> trees;
long long int tallest = 0;

long long int total_length(long long int cutter){
  long long int sum = 0;
  for(int i = 0 ; i < trees.size() ; i++){
    if(trees[i] > cutter) sum = sum + (trees[i] - cutter);
  }
  return sum;
}
int main(){
  long long int N, M;
  std::cin >> N >> M;
  long long int tallest = 0;
  long long int shortest = 1;

  for(int i = 0 ; i < N ; i++){
    long long int temp;
    std::cin >> temp;
    trees.push_back(temp);
    tallest = std::max(tallest, temp);
  }

  while(shortest <= tallest){
    long long int mid = (shortest + tallest) / 2;
    long long int sum = total_length(mid);

    if(sum < M){
      tallest = mid - 1;
    }
    else{
      shortest = mid + 1;
    }
  }
  std::cout << tallest;


  return 0;
}
