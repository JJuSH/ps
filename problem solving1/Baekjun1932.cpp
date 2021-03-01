#include <string>
#include <iostream>
int triangle[500][500];
int layer_index[500][500];

void calculate(int N){
  for(int i = 1; i < N ; i++){
    layer_index[i][0] = layer_index[i-1][0] + triangle[i][0];
    for(int j = 1; j < i ; j++){
      layer_index[i][j] = std::max(layer_index[i-1][j-1] + triangle[i][j],layer_index[i-1][j] + triangle[i][j]);
    }
    layer_index[i][i] = layer_index[i-1][i-1] + triangle[i][i];
  }
  return;
}
int main() {
  int N;
  std::cin >> N;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0; j < i+1 ; j++){
      std::cin >> triangle[i][j] ;
    }
  }

  layer_index[0][0] = triangle[0][0];
  calculate(N);
  int maximum = 0;
  for(int i = 0; i < N ; i++){
    if(maximum < layer_index[N-1][i]){
      maximum = layer_index[N-1][i];
    }
  }
  std::cout << maximum << std::endl;
  return 0;
}
