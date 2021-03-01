#include<iostream>
#include<vector>

std::vector<int> airline[2001];
int test_case;
int num_city, airline_num;

int main(){
    std::cin >> test_case;
    for(int i = 0 ; i < test_case ; i++){
        std::cin >> num_city >> airline_num;
        for(int j = 0 ; j < airline_num ; j++){
            int a, b;
            std::cin >> a >> b;
            airline[a].push_back(b);
            airline[b].push_back(a);
        }
        std::cout << num_city - 1 << "\n";
    }
    return 0;
}
