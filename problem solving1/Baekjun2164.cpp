#include<iostream>
#include<queue>

int main(){
  std::queue<int> q;
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    q.push(i+1);
  }
  for(int i = 0 ; i < N-1 ; i++){
    q.pop();
    q.push(q.front());
    q.pop();
  }
  std::cout << q.front();
  return 0;
}
