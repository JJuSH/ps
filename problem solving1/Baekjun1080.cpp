#include<iostream>
#include<string>
int R, C;
int bef[50][50];
int aft[50][50];

void flip(int r_start, int c_start, int r_end , int c_end){
    for(int i = r_start ; i <= r_end ; i++){
        for(int j = c_start ; j <= c_end ; j++){
            //bef[i][j] = (bef[i][j] == 1) ? 0 : 1;
            if(bef[i][j] == 1) bef[i][j] = 0;
            else bef[i][j] = 1;
         }
    }
}

int main(){
    std::cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0 ; j < C ; j++){
            bef[i][j] = s[j] - 48;
        }
    }
    for(int i = 0 ; i < R ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0 ; j < C ; j++){
            aft[i][j] = s[j] - 48;
        }
    }
    int count = 0;
    for(int i = 0 ; i <= R - 3 ; i++){
        for(int j = 0 ; j <= C - 3 ; j++){
            if(bef[i][j] != aft[i][j]){
                //std::cout << " if in " << "\n";
                flip(i, j, i + 2 , j + 2);
                count++;
            }
        }
    }
    if(check(0 , 0 , R - 1 , C - 1)) std::cout << count << "\n";
    else std::cout << -1 << "\n";
    return 0;
}
