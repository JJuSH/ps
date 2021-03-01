#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<utility>

int row, col;
int maze[100][100];
bool explored[100][100] = {false,};
int dist[100][100] = {0};
std::queue<std::pair<int,int> > q;

int count;

void bfs(){
    explored[0][0] = true;
    q.push(std::make_pair(0,0));
    dist[0][0] = 0;
    while(q.size() != 0){
        int r = q.front().first;
        int c = q.front().second;
        explored[r][c] = true;
        q.pop();
        count++;
        if((r+1 <= row-1) && (maze[r+1][c] == 1) && (explored[r+1][c] == false)){
            explored[r+1][c] = true;
            q.push(std::make_pair(r+1,c));
            dist[r+1][c] = dist[r][c] + 1;
        }
        if((c+1 <= col-1) && (maze[r][c+1] == 1) && (explored[r][c+1] == false)){
            explored[r][c+1] = true;
            q.push(std::make_pair(r,c+1));
            dist[r][c+1] = dist[r][c] + 1;
        }
        if((c -1 >= 0) && (maze[r][c-1] == 1) && (explored[r][c-1] == false)){
            explored[r][c-1] = true;
            q.push(std::make_pair(r,c-1));
            dist[r][c-1] = dist[r][c] + 1;
        }
        if((r-1 >= 0) && (maze[r-1][c] == 1) && (explored[r-1][c] == false)){
            explored[r-1][c] = true;
            q.push(std::make_pair(r-1,c));
            dist[r-1][c] = dist[r][c] + 1;
        }
    }
}

int main(){
    std::cin >> row >> col;
    count = 0;
    for(int i = 0 ; i < row ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0 ; j < col ; j++){
            maze[i][j] = s[j]-48;
        }
    }
    bfs();
    std::cout << dist[row-1][col-1] + 1<< "\n";
    
    return 0;
}
