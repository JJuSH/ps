#include<iostream>
int paper[128][128];
int blue = 0;
int white = 0;

bool divide(int x, int y, int N){
  int sum = paper[x][y];
  bool check = true;
  for(int i = 0; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      if(sum != paper[x+i][y+j]){
        check = false;
        break;
      }
    }
  }
  return check;
}

void DandQ(int x, int y, int N){
  if(N == 1){
    if(paper[x][y] == 1) blue++;
    else white++;
    return;
  }
  else{
    if(divide(x,y,N)){
      if(paper[x][y] == 1) blue++;
      else white++;
      return;
    }
    else{
      DandQ(x,y,N/2);
      DandQ(x + N/2 , y, N/2);
      DandQ(x , y + N/2 , N/2);
      DandQ(x + N/2 , y + N/2, N/2);
      return;
    }
  }

}

int main(){
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      std::cin >> paper[i][j];
    }
  }
  DandQ(0,0,N);
  std::cout << white << "\n";
  std::cout << blue << "\n"
  return 0;
}
