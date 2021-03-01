#include<iostream>

int n;
int m;
int arr[9];
bool check[10] = {false,};

void dfs(int length, int current){
  if(length == m){
    for(int i = 0 ; i < m ; i++){
      std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;
    return;
  }
    else{
      for(int i = current+1; i <= n ; i++){
        if(check[i] == false){
          check[i] = true;
          arr[length] = i;
          dfs(length+1,i);
          check[i] = false;
        }
      }
    }

  }

int main(){
  std::cin >> n >> m ;
  dfs(0,0);
  return 0;
}
