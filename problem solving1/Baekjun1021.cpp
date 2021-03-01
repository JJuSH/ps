#include<iostream>
#include<deque>
std::deque<int> deq;
void move_right(int n){
  for(int i = 0 ; i < n ; i++){
    deq.push_front(deq.back());
    deq.pop_back();
  }
}
void move_left(int n){
  for(int i = 0 ; i < n ; i++){
    deq.push_back(deq.front());
    deq.pop_front();
  }
}

int main(){

  int N, G;
  int get_num[50];
  std::cin >> N >> G;
  for(int i = 0 ; i < N ; i++){
    deq.push_back(i+1);
  }
  for(int i = 0 ; i < G ; i ++){
    std::cin >> get_num[i];
  }
  int op_2 = 0;
  int op_3 = 0;

  for(int i = 0 ; i < G ; i++){
    int target = get_num[i];
    int index;
    for(int j = 0 ; j < deq.size() ; j++){
      if(deq[j] == target) index = j;
    }
    if(index < deq.size()-index){
      move_left(index);
      deq.pop_front();
      op_2 = op_2 + index;
    }
    else{
      int iter = deq.size() - index;
      move_right(iter);
      deq.pop_front();
      op_3 = op_3 + iter;
    }
  }

  std::cout << op_2 + op_3;
  return 0;
}
