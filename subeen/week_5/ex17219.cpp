#include <iostream>
#include <map>
using namespace std;

int main() {
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   int N, M;
   map<string, string> m;
   string key, value;

   cin >> N >> M;

   for (int i = 0; i < N; i++) {
       cin >> key >> value;
       m[key] = value;
   }

   for (int i = 0; i < M; i++) {
       cin >> key;
       cout << m[key] << "\n";
   }
    
   return 0;
}