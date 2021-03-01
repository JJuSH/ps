#include<iostream>
#include<string.h>
int R, C;
int time_step = 0;
int field[300][300];
int after_step[300][300];
bool visited[300][300];
void dfs(int r, int c){
    //std::cout << "dfs " << r << " " << c << "\n";
    visited[r][c] = true;
    int zero_count = 0;
    if(r + 1 < R && visited[r + 1][c] == false){
        if(field[r + 1][c] == 0) zero_count++;
        else dfs(r + 1, c);
    }
    if(r - 1 >= 0 && visited[r - 1][c] == false){
        if(field[r - 1][c] == 0) zero_count++;
        else dfs(r - 1 , c);
    }
    if(c + 1 < C && visited[r][c + 1] == false){
        if(field[r][c + 1] == 0) zero_count++;
        else dfs(r, c + 1);
    }
    if(c - 1 >= 0 && visited[r][c - 1] == false){
        if(field[r][c - 1] == 0) zero_count++;
        else dfs(r, c - 1);
    }
    after_step[r][c] = zero_count;
}


int main(){
    std::cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            std::cin >> field[i][j];
        }
    }
    while(true){
        //std::cout << " while " << time_step << "\n";
        memset(visited, false, sizeof(visited));
        memset(after_step, 0 , sizeof(after_step));
        int num_iceberg = 0 ;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(field[i][j] != 0 && visited[i][j] == false){
                    dfs(i,j);
                    num_iceberg++;
                }
            }
        }
        //std::cout << "num_iceberg " << num_iceberg << "\n";
        if(num_iceberg > 1) break;
        else if(num_iceberg == 0){
            time_step = 0;
            break;
        }
        else{
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C ; j++){
                    if(field[i][j] >= after_step[i][j]) field[i][j] = field[i][j] - after_step[i][j];
                    else field[i][j] = 0;
                }
            }
            time_step++;
        }
    }
    std::cout << time_step << "\n";
    return 0;
}
