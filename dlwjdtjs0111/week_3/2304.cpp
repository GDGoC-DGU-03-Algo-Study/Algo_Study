#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, max_pos=0, max_high=0;
    cin >> N;
    int arr[1001];
    fill_n(arr, 1001, 0);
    for(int i = 0; i < N; i++){
        int L, H;
        cin >> L >> H;
        arr[L] = H;
        if(max_high < H) {
            max_pos = L;
            max_high = H;
        } 
    }
    
    int a = max_high;

    int Lmax = 0;
    for(int i = 1; i < max_pos; i++) {
        Lmax = max(Lmax, arr[i]);
        a += Lmax;
    }
    int Rmax = 0;
    for(int i = 1000; i > max_pos; i--) {
        Rmax = max(Rmax, arr[i]);
        a += Rmax;
    }
    cout << a;
}