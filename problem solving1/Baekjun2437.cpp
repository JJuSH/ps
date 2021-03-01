#include<iostream>
#include<algorithm>
int N, sum = 0;
int arr[1001];

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N);
    for(int i = 0 ; i <= N ; i++){
        if(arr[i] > sum + 1){
            break;
        }
        sum += arr[i];
    }
    std::cout << sum + 1 << "\n";
    return 0;
}
