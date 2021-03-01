#include<iostream>
char field[20][20];
bool visited[26]; // A = 65
int R, C;
int max_step = 0;

bool move(int r, int c){
    bool can_move = false;
    if(r + 1 <= R - 1 && visited[field[r + 1][c] - 65] == false) can_move = true;
    if(r - 1 >= 0 && visited[field[r - 1][c] - 65] == false) can_move = true;
    if(c + 1 <= C - 1 && visited[field[r][c + 1] - 65] == false) can_move = true;
    if(c - 1 >= 0 && visited[field[r][c - 1] - 65] == false) can_move = true;
    
    return can_move;
}

void back_track(int r, int c, int step){
    
    if(move(r,c) == false){
        //std::cout << "dead end " << field[r][c] << "\n";
        max_step = std::max(max_step, step);
        return;
    }
    if(r + 1 <= R - 1 && visited[field[r + 1][c] - 65] == false){
        visited[field[r + 1][c] - 65] = true;
        back_track(r + 1 , c , step + 1);
        visited[field[r + 1][c] - 65] = false;
    }
    if(r - 1 >= 0 && visited[field[r - 1][c] - 65] == false){
        visited[field[r - 1][c] - 65] = true;
        back_track(r - 1 , c , step + 1);
        visited[field[r - 1][c] - 65] = false;
    }
    if(c + 1 <= C - 1 && visited[field[r][c + 1] - 65] == false){
        visited[field[r][c + 1] - 65] = true;
        back_track(r , c + 1 , step + 1);
        visited[field[r][c + 1] - 65] = false;
    }
    if(c - 1 >= 0 && visited[field[r][c - 1] - 65] == false){
        visited[field[r][c - 1] - 65] = true;
        back_track(r , c - 1 , step + 1);
        visited[field[r][c - 1] - 65] = false;
    }
    
    
}
int main(){
    std::cin >> R >> C;
    std::string s1;
    for(int i = 0 ; i < R ; i++){
        std::cin >> s1;
        for(int j = 0 ; j < C ; j++){
            field[i][j] = s1[j];
        }
    }
    visited[field[0][0] - 65] = true;
    back_track(0,0,1);
    
    std::cout << max_step << "\n";
    
    return 0;
}
