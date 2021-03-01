#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<utility>

int row, col;
int tomato[1000][1000];
bool explored[1000][1000] = {false,};
int day[1000][1000] = {0};
std::queue<std::pair<int,int> > q;
int target = 0;
int max_day = 1;

void bfs(){
    while(q.size() != 0){
        int r = q.front().first;
        int c = q.front().second;
        explored[r][c] = true;
        q.pop();
        if((r+1 <= row-1) && (tomato[r+1][c] == 0) && (explored[r+1][c] == false)){
            explored[r+1][c] = true;
            q.push(std::make_pair(r+1,c));
            day[r+1][c] = day[r][c] + 1;
            max_day = std::max(max_day,day[r+1][c]);
            target--;
        }
        if((c+1 <= col-1) && (tomato[r][c+1] == 0) && (explored[r][c+1] == false)){
            explored[r][c+1] = true;
            q.push(std::make_pair(r,c+1));
            day[r][c+1] = day[r][c] + 1;
            max_day = std::max(max_day,day[r][c+1]);
            target--;
        }
        if((c -1 >= 0) && (tomato[r][c-1] == 0) && (explored[r][c-1] == false)){
            explored[r][c-1] = true;
            q.push(std::make_pair(r,c-1));
            day[r][c-1] = day[r][c] + 1;
            max_day = std::max(max_day,day[r][c-1]);
            target--;
        }
        if((r-1 >= 0) && (tomato[r-1][c] == 0) && (explored[r-1][c] == false)){
            explored[r-1][c] = true;
            q.push(std::make_pair(r-1,c));
            day[r-1][c] = day[r][c] + 1;
            max_day = std::max(max_day,day[r-1][c]);
            target--;
        }
    }
}

int main(){
    std::cin >> col >> row;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            std::cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                day[i][j] = 1;
                explored[i][j] = true;
                q.push(std::make_pair(i,j));
            }
            else if(tomato[i][j] == 0){
                target++;
            }
        }
    }
    bfs();
    if(target == 0){
        if(max_day == 1) std::cout << 0 << "\n";
        else std::cout << max_day-1 << "\n";
    }
    else std::cout << -1 << "\n";
    return 0;
}

