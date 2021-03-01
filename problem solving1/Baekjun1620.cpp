#include<iostream>
#include<map>
#include<string>
std::map<std::string, int> field;
std::string v[100001];
int M, N;
int main(){
    std::cin.tie(NULL);
    std::ios::ios_base::sync_with_stdio(false);
    
    std::cin >> M >> N;
    for(int i = 1 ; i <= M ; i++){
        std::string s;
        std::cin >> s;
        field.insert(std::make_pair(s,i));
        v[i] = s;
    }
    for(int i = 0 ; i < N ; i++){
        std::string sn;
        std::cin >> sn;
        if(sn[0] >= 65 && sn[0] <=90){
            std::cout << field[sn] << "\n";
        }
        else{
            std::cout << v[std::stoi(sn)] << "\n";
        }
    }
    return 0;
}
