#include<iostream>
int arr[100000];

void swap(int a, int b){
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int divide(int left, int right){
    int mid = (left + right)/2;
    swap(left, mid);
    
    int piv = arr[left];
    int i = left;
    int j = right;
    
    while(i < j){
        while(arr[j] > piv) j--;
        while(i < j && arr[i] <= piv) i++;
        swap(i , j);
    }
    swap(left, i);
    return i;
}

void quick_sort(int l, int r){
    if(l >= r) return;
    else{
        int piv_pos = divide(l, r);
        quick_sort(l, piv_pos-1);
        quick_sort(piv_pos + 1, r);
    }
}

int main(){
    int N;
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) std::cin >> arr[i];
    quick_sort(0 , N-1);
    for(int i = 0 ; i < N ; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    return 0;
}
