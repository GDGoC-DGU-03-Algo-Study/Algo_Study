#include <iostream>
using namespace std;
int n, w, l;
int trucks[1001], bridge[101];

int main() {

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) cin >> trucks[i];

    int time = 0, out = -1, in = 0, weight = 0;

    while (in < n || weight) {
        time++;
        out = (out + 1) % (w + 1);
        int end = (out + 1) % (w + 1);

        if (bridge[end]) { // end에 트럭 있으면
            weight -= bridge[end]; //트럭 제거
            bridge[end] = 0;
        }

        if (in < n && weight + trucks[in] <= l) {
            // 트럭이 다리에 올라갈 수 있다면
            bridge[out] = trucks[in];
            weight += trucks[in++];
        }
    }
    cout << time;
}