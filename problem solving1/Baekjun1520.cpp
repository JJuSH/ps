#include<iostream>
#include<string.h>
int row, col;
int land[500][500];
int path[500][500];

int find_path(int r, int c){
  if(path[r][c] != 0x3f3f3f3f){
    return path[r][c];
  }
  else{
    path[r][c] = 0;
    if((r>0) && (land[r][c] < land[r-1][c])){
      path[r][c] = path[r][c] + find_path(r-1,c);
    }
    if((c>0) && (land[r][c] < land[r][c-1])){
      path[r][c] = path[r][c] + find_path(r,c-1);
    }
    if((c<col-1) && (land[r][c] < land[r][c+1])){
      path[r][c] = path[r][c] + find_path(r,c+1);
    }
    if((r<row-1) && (land[r][c] < land[r+1][c])){
      path[r][c] = path[r][c] + find_path(r+1,c);
    }
    return path[r][c];
  }
}

int main(){
  std::cin >> row >> col;
  memset(path, 0x3f, sizeof(path));
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      std::cin >> land[i][j];
    }
  }
  path[0][0] = 1;
  std::cout << find_path(row-1,col-1);
  return 0;
}
