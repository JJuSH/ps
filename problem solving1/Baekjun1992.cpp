#include<iostream>
#include<string>
int image[64][64];

bool divide(int x, int y, int N){
  int flag = image[x][y];
  bool check = true;
  for(int i = 0; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      if(flag != image[x+i][y+j]){
        check = false;
        break;
      }
    }
  }
  return check;
}

void DandQ(int x, int y, int N){

  if(divide(x,y,N)){
    if(image[x][y] == 1) std::cout << 1;
    else std::cout << 0;
  }
  else{
    std::cout << "(";
    DandQ(x,y,N/2);
    DandQ(x , y + N/2 , N/2);
    DandQ(x + N/2 , y, N/2);
    DandQ(x + N/2 , y + N/2, N/2);
    std::cout << ")";
  }

  return;

}

int main(){
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    std::string s;
    std::cin >> s;
    for(int j = 0 ; j < N ; j++){
      image[i][j] = s[j] - 48;
    }
  }
  DandQ(0,0,N);
  return 0;
}
