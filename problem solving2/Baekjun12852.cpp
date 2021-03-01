#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>

std::vector<std::pair<int, int> > v;

int main(){
    int N;
    std::cin >> N;
    v.push_back(std::make_pair(0,0));
    v.push_back(std::make_pair(0,1));
    v.push_back(std::make_pair(1,1));
    
    for(int i = 3; i <= N ; i++){
        
        if(i % 3 == 0 || i % 2 == 0){
            if(i % 3 == 0 && i % 2 == 0){
                int prev1 = i / 3;
                int prev2 = i / 2;
                int count = std::min( std::min(v[prev1].first + 1 , v[prev2].first + 1) , v[i-1].first + 1);
                
                if(count == v[prev1].first + 1){
                    v.push_back(std::make_pair(count , prev1));
                }
                else if(count == v[prev2].first + 1){
                    v.push_back(std::make_pair(count , prev2));
                }
                else{
                    v.push_back(std::make_pair(count , i - 1));
                }
            }
            else if(i % 3 == 0){
                int prev = i / 3;
                int count = std::min(v[prev].first + 1, v[i-1].first + 1);
                if(count == v[prev].first + 1){
                    v.push_back(std::make_pair(count , prev));
                }
                else{
                    v.push_back(std::make_pair(count , i - 1));
                }
            }
            else{
                int prev = i / 2;
                int count = std::min(v[prev].first + 1, v[i-1].first + 1);
                if(count == v[prev].first + 1){
                    v.push_back(std::make_pair(count , prev));
                }
                else{
                    v.push_back(std::make_pair(count , i - 1));
                }
            }
        }
        else{
            v.push_back(std::make_pair(v[i-1].first + 1, i - 1));
        }
    }
    std::cout << v[N].first << "\n";
    std::cout << N << " ";
    while(N != 1){
        std::cout << v[N].second << " ";
        N = v[N].second;
    }
    std::cout << "\n";
    return 0;
}
