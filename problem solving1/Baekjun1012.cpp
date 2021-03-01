#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
int r,c,bc;
int baat[50][50];
bool explored[50][50] = {false,};
int count;
std::queue<int> q;
void dfs(int row, int col){
    //std::cout << "dfs" << row << col << "\n";
    explored[row][col] = true;
    if((row-1 >= 0) && (baat[row-1][col] == 1) && (explored[row-1][col] == false)){
        dfs(row-1,col);
    }
    if((row+1 <= r-1) && (baat[row+1][col] == 1) && (explored[row+1][col] == false)){
        dfs(row+1,col);
    }
    if((col -1 >= 0) && (baat[row][col-1] == 1) && (explored[row][col-1] == false)){
        dfs(row,col-1);
    }
    if((col+1 <= c-1) && (baat[row][col+1] == 1) && (explored[row][col+1] == false)){
        dfs(row,col+1);
    }
    return;
}

int main(){
    int case_num;
    std::cin >> case_num;
    for(int i = 0 ; i < case_num ; i++){
        memset(baat,0,sizeof(baat));
        memset(explored,0,sizeof(explored));
        count = 0;
        std::cin >> c >> r >> bc;
        for(int i = 0 ; i < bc ; i++){
            int M, N;
            std::cin >> M >> N;
            baat[N][M] = 1;
            
        }
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if((baat[i][j] == 1) && (explored[i][j] == false)){
                    count++;
                    dfs(i,j);
                }
                else continue;
            }
        }
        q.push(count);
        //std::cout << count << "\n";
    }
    while(q.size() != 0){
        std::cout << q.front() << "\n";
        q.pop();
    }
        return 0;
}
