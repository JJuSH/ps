#include<iostream>
int task[16][2]; // len value
int memo[16];

int N;
int max;

int func(int day){
    if (day > N + 1) return -999999999;
    else if(day == N + 1) return 0;
    else{
        if(memo[day] != -1) return memo[day];
        else{
            return memo[day] = std::max(func(day + 1), func(day + task[day][0]) + task[day][1]);
        }
    }
}
int main(){
    std::cin >> N;
    for(int i = 1 ; i <= N ; i++){
        std::cin >> task[i][0] >> task[i][1];
    }
    for(int i = 1 ; i <= N ; i++){
        memo[i] = -1;
    }
    std::cout << func(1) << "\n";
    return 0;
}
