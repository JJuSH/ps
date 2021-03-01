#include<iostream>
#include<stack>
#include<vector>

int main(){
  std::stack<int> s;
  std::vector<char> v;
  int N;
  std::cin >> N;
  int temp;

  int source = 0;
  bool possible = true;
  for(int i = 0 ; i < N ; i++){
    std::cin >> temp;

    if(temp > source){
      while(source != temp){
        source++;
        s.push(source);
        v.push_back('+');
      }
      s.pop();
      v.push_back('-');
    }
    else{
      if(s.top() == temp){
        s.pop();
        v.push_back('-');
      }
      else {
        possible = false;
      }
    }
  }
  if(possible == true){
    for(std::vector<int>::size_type i =0; i<v.size(); i++){
      std::cout << v[i] << "\n";
    }
  }
  else{
    std::cout << "NO" ;
  }

  return 0;
}
