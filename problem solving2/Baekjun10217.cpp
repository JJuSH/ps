#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
int len;
int l, r;
int target;
int count = 0;
std::vector<int> v;

void two_pointer(){
    while(true){
        if(l == r) break;
        else{
            if(v[l] + v[r] < target){
                l++;
            }
            else if(v[l] + v[r] > target){
                r--;
            }
            else if(v[l] + v[r] == target){
                count++;
                l++;
            }
        }
        
    }
}
int main(){
    std::cin >> len;
    l = 0;
    r = len-1;
    
    for(int i = 0 ; i < len ; i++){
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    std::cin >> target;
    std::sort(v.begin(), v.end());
    two_pointer();
    std::cout << count << "\n";
    return 0;
}
