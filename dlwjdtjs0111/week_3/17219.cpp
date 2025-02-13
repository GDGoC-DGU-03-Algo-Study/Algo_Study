#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, string> m;
vector<string> v;

int main() {
    int N, M;
    string str, key, value;
    cin >> N >> M;
    cin.ignore();

    for(int i = 0; i < N; i++) {
        getline(cin, str);
        key = str.substr(0, str.find(" "));
        value = str.substr(str.find(" ") + 1, str.length());
        m.insert(make_pair(key, value));
    }
    for(int i = 0; i < M; i++) {
        getline(cin, str); 
        if(m.find(str) != m.end()){
            auto it = m.find(str);
            v.push_back(it->second);
        }
    }
    for(int i = 0; i < M; i++) {
        cout << v[i] << endl;
    }
}