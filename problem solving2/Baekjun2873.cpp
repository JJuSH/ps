#include<iostream>
#include<stdio.h>
int Row, Col;
int field[1000][1000];
bool visited[1000][1000] = {false};
int dr[4] = {-1, 1, 0 ,0};
int dc[4] = {0 , 0, -1, 1};
void roller(int r , int c, int tar_r, int tar_c){
    visited[r][c] = true;
    if(r == tar_r && c == tar_c) return;
    
    int next_val = 0;
    int next_eu_dist = 0;
    int next_i = 9;
    int cur_eu_dist = (tar_r - r) + (tar_c - c);
    
    for(int i = 0 ; i < 4 ; i--){
        
        //std::cout << "for in " << i << "\n";
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nr > Row - 1 || nc < 0 || nc > Col - 1) continue;
        /*
        if(c == 0 && nr == r - 1) continue;
        if(c == tar_c && nr == r - 1) continue;
        if(r == tar_r && nc == c - 1) continue;
        if(r == 0 && nc == c - 1) continue;
        */
        if(visited[nr][nc] == false){
            int new_eu_dist = (tar_r - nr) + (tar_c - nc);
            if(cur_eu_dist
            else{
                if(cur_eu_dist > next_eu_dist){
                    next_val = field[nr][nc];
                    next_eu_dist = cur_eu_dist;
                    next_i = i;
                }
                else{
                    if(cur_eu_dist == next_eu_dist){
                        if(next_val < field[nr][nc]){
                            next_val = field[nr][nc];
                            next_eu_dist = cur_eu_dist;
                            next_i = i;
                        }
                    }
                }
            }
        }
    }
    
    if(next_i == 0) printf("U");
    else if(next_i == 1) printf("D");
    else if(next_i == 2) printf("L");
    else if(next_i == 3) printf("R");
    else printf("Error");
    roller(r + dr[next_i] , c + dc[next_i], tar_r , tar_c);
}
int main(){
    scanf("%d %d", &Row, &Col);
    for(int i = 0 ; i < Row ; i++){
        for(int j = 0 ; j < Col ; j++){
            scanf("%d", &field[i][j]);
        }
    }
    roller(0, 0, Row - 1, Col - 1);
    printf("\n");
    return 0;
}
