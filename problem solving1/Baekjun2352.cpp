#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
int N;
std::vector<int> v;

void print_v(){
    std::cout << "v------" << "\n";
    for(int i : v){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
void bs(int n){
    if(v.size() == 0) v.push_back(n);
    else{
        int end = v.size() - 1;
        if(v[end] < n) v.push_back(n);
        else{
            auto i = lower_bound(v.begin(), v.end() , n);
            *i = n;
        }
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        int temp;
        scanf("%d", &temp);
        bs(temp);
        //print_v();
    }
    std::cout << v.size() << "\n";
    return 0;
}
