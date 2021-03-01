#include<iostream>
#include<string>
#include<vector>
#include<stack>

int main(){
  std::string sentence;
  while(true){
    std::getline(std::cin, sentence);
    if((sentence[0] == '.') && (sentence.size() == 1)) break;
    std::stack<int> stk;
    bool check = true;

    for(int i = 0; i < sentence.length() ; i++){
      if(sentence[i] == '(') stk.push(1);
      else if(sentence[i] == '[') stk.push(2);
      else if(sentence[i] == ')'){
        if((stk.size() != 0) && (stk.top() == 1)) stk.pop();
        else{
          check = false;
          break;
        }
      }
      else if(sentence[i] == ']'){
        if((stk.size() != 0) && (stk.top() == 2)) stk.pop();
        else{
          check = false;
          break;
        }
      }
    }

    if( check && (stk.size() == 0)){
      std::cout << "yes" << std::endl;
    }
    else{
      std::cout << "no" << std::endl;
    }

  }
  return 0;
}
