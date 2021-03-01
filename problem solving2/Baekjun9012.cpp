#include<iostream>
#include<vector>
#include<string>
int main(){
  int N;

  std::cin >> N;
  for(int i = 0; i < N ; i++){
    std::vector<int> v;
    std::string paren;
    bool valid = true;
    std::cin >> paren;

    for(int j = 0; j < paren.length() ; j++){
      if(paren[j] == '('){
        v.push_back(1);
      }
      else if(paren[j] == ')'){
        if(v.size() != 0){
          v.pop_back();
        }
        else{
          valid = false;
          break;
        }
      }
    }

    if(valid && (v.size() == 0)){
      std::cout << "YES" << std::endl;
    }
    else{
      std::cout << "NO" << std::endl;
    }

  }
  return 0;
}
