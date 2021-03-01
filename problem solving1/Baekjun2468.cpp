#include<iostream>
#include<string.h>
int land[100][100];
int N;
bool after_rain[100][100];
bool visited[100][100];

void make_after_rain(int r){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(land[i][j] > r) after_rain[i][j] = true;
            else after_rain[i][j] = false;
        }
    }
}
void print_land(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cout << land[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void dfs(int i, int j){
    visited[i][j] = true;
    if((i-1) >=0 && visited[i-1][j] == false && after_rain[i-1][j] == true){
        dfs(i-1,j);
    }
    if((i+1) < N && visited[i+1][j] == false && after_rain[i+1][j] == true){
        dfs(i+1,j);
    }
    if((j-1) >=0 && visited[i][j-1] == false && after_rain[i][j-1] == true){
        dfs(i,j-1);
    }
    if((j+1) < N && visited[i][j+1] == false && after_rain[i][j+1] == true){
        dfs(i,j+1);
    }
}
int main(){
    std::cin >> N;
    int max_height = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> land[i][j];
            max_height = std::max(max_height, land[i][j]);
        }
    }
    int maxi = 0;
    //std::cout << "max_height " << max_height << "\n";
    for(int i = 0 ; i <= max_height ; i++){
        make_after_rain(i);
        memset(visited, 0 , sizeof(visited));
        //print_land();
        int ans = 0;
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                if(after_rain[j][k] == true && visited[j][k] == false){
                    //std::cout << "j k " << j << " " << k << "\n";
                    dfs(j,k);
                    ans++;
                }
            }
        }
        maxi = std::max(maxi, ans);
    }
    std::cout << maxi << "\n";
    return 0;
}
