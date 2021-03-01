#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> n;
std::vector<int> p;
int N;

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        int temp;
        std::cin >> temp;
        if(temp > 0) p.push_back(temp);
        else n.push_back(temp);
    }
    std::sort(p.begin(), p.end());
    std::sort(n.begin(), n.end());
    
    long long int sump = 0;
    long long int sumn = 0;
    
    bool flag = true;
    int cur_num = 0;
    
    for(auto iter = p.end() - 1 ; iter != p.begin() - 1 ; iter--){
        if(iter == p.begin() && flag) sump += (*iter);
        else if((*iter) == 1){
            sump += 1 + cur_num;
            cur_num = 0;
        }
        else{
            if(flag){
                cur_num = *iter;
                flag = false;
            }
            else{
                sump += cur_num * (*iter);
                cur_num = 0;
                flag = true;
            }
        }
    }
    flag = true;
    cur_num = 0;
    for(auto iter = n.begin() ; iter != n.end() ; iter++){
        if(iter == n.end() - 1 && flag) sumn += (*iter);
        else{
            if(flag){
                cur_num = *iter;
                flag = false;
            }
            else{
                sumn += cur_num * (*iter);
                flag = true;
            }
        }
    }
    std::cout << sumn + sump << "\n";
    return 0;
}
