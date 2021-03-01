#include<iostream>
#define INF 987654321

int max_heap[100000];
int length = 1;
void update_q_insert(int index){
    int next_index = index / 2;
    if(next_index < 1) return;
    else{
        if(max_heap[index] > max_heap[next_index]){
            int temp = max_heap[index];
            max_heap[index] = max_heap[next_index];
            max_heap[next_index] = temp;
            update_q_insert(next_index);
        }
    }
}
void insert_q(int n){
    max_heap[length] = n;
    update_q_insert(length);
    length++;
}
void update_q_delete(int index){
    int l = ((index * 2) < length) ? max_heap[2*index] : -INF;
    int r = ((index * 2 + 1 ) < length) ? max_heap[2*index + 1] : -INF;
    
    int max_ = std::max(l ,r);
    int next_index = (max_ == l) ? 2*index : 2*index + 1 ;
    
    if(max_ != -INF && max_ > max_heap[index]){
        int temp = max_heap[index];
        max_heap[index] = max_heap[next_index];
        max_heap[next_index] = temp;
        update_q_delete(next_index);
    }
    else return;
}
int delete_q(){
    if(length == 1) return -1;
    int return_val = max_heap[1];
    length--;
    max_heap[1] = max_heap[length];
    update_q_delete(1);
    return return_val;
}
void print_q(){
    std::cout << "current q : ";
    for(int i = 1 ; i < length ; i++){
        std::cout << max_heap[i] << " ";
    }
    std::cout << "\n";
}
int main(){
    /*
    while(true){
        int temp;
        
        std::cin >> temp;
        if(temp == 0){
            int deleted = delete_q();
            if(deleted == -1) std::cout << "Heap is empty " << "\n";
            else std::cout << deleted << " deleted" << "\n";
            print_q();
        }
        else{
            insert_q(temp);
            print_q();
        }
    }
    */
    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        int temp;
        std::cin >> temp;
        insert_q(temp);
    }
    std::cout << "\n";
    while(length != 1){
        std::cout << delete_q() << " ";
    }
    std::cout << "\n";

}
