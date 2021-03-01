#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define MAX 2000000000

int N;
long long int sum = MAX;
int l, r;
int saved_l, saved_r;

std::vector<long long int> sol;

void tp(){
    while(l<r){
        
        if(sol[l] + sol[r] == 0){
            saved_r = r;
            saved_l = l;
            break;
        }
        else{
            if(sol[l] + sol[r] > 0){
                if(sum > abs(sol[l] + sol[r])){
                    sum = abs(sol[l] + sol[r]);
                    saved_r = r;
                    saved_l = l;
                }
                r--;
            }
            else{
                if(sum > abs(sol[l] + sol[r])){
                    sum = abs(sol[l] + sol[r]);
                    saved_r = r;
                    saved_l = l;
                }
                l++;
            }
        }
    }
}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        int temp;
        std::cin >> temp;
        sol.push_back(temp);
    }
    std::sort(sol.begin() , sol.end());
    l = 0;
    r = N-1;
    tp();
    if(sol[saved_l] < sol[saved_r]) std::cout << sol[saved_l] << " " << sol[saved_r] << "\n";
    else std::cout << sol[saved_r] << " " << sol[saved_l] << "\n";
    return 0;
}
