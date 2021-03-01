#include<iostream>
#include<map>
int num_case, num_line;
int par[200001];
int counter[200001];

int find(int a){
    if(par[a] == a) return a;
    else{
        int pa = find(par[a]);
        par[a] = pa;
        return par[a];
    }
}

void uni(int a, int b){
    int pa = par[a];
    int pb = par[b];
    if(pa == pb) return;
    else{
        par[pb] = pa;
        counter[pa] = counter[pa] + counter[pb];
        counter[pb] = 1;
    }
}

int main(int argc, const char * argv[]){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> num_case;
    for(int i = 0 ; i < num_case ; i++){
        int value = 0;
        std::cin >> num_line;
        std::string name1, name2;
        std::map<std::string , int> pool;
        for(int j = 0 ; j < 2*num_line ; j++){
            par[j] = j;
            counter[j] = 1;
        }
        for(int j = 0 ; j < num_line ; j++){
            std::cin >> name1;
            std::cin >> name2;
            
            if(pool.count(name1) == 0){
                pool[name1] = value;
                value++;
            }
            if(pool.count(name2) == 0){
                pool[name2] = value;
                value++;
            }
            
            int value1 = pool[name1];
            int value2 = pool[name2];
            
            uni(value1, value2);
            
            printf("%d\n" , counter[find(value1)]);
            //printf("%d\n", count(par[value1]));
            
        }
    }
    return 0;
}
