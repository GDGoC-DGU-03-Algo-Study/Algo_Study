#include <iostream>
using namespace std;
int main() {
    int E, S, M, year = 1;
    cin >> E >> S >> M;
    while(1) {
        if((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
            break;
        } else year += 1;
       
    }
    cout << year;
}