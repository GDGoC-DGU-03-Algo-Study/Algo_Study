#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int N, K, x, y, L, X;
    char C;
    vector<pair<int, int>> apple;
    map<int, char> curve;
    deque<pair<int, int>> DQ;
    set<pair<int, int>> snakeBody;
    pair<int, int> currentHead = make_pair(1, 1);
    map<char, pair<int, int>> direction = {
        {'R', {0, 1}}, {'L', {0, -1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
    map<char, char> rightTurn = {{'R', 'D'}, {'D', 'L'}, {'L', 'U'}, {'U', 'R'}};
    map<char, char> leftTurn = {{'R', 'U'}, {'U', 'L'}, {'L', 'D'}, {'D', 'R'}};

    // int currentLength = 1;
    int count = 0;
    DQ.push_front(currentHead);
    snakeBody.insert(currentHead);
    char currentCurve = 'R';
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        apple.push_back(make_pair(x, y));
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> C;
        curve[X] = C;
    }

    bool isGameOver = false;
    while (!isGameOver)
    {
        int currentCol = currentHead.first;
        int currentRow = currentHead.second;
        count++;
        pair<int, int> moveHead = make_pair(currentCol + direction[currentCurve].first,
                                            currentRow + direction[currentCurve].second);

        if (snakeBody.count(moveHead))
        {
            isGameOver = true;
            break; // 자기 자신과 충돌하면 종료
        }

        if (moveHead.first > N || moveHead.first < 1 || moveHead.second > N || moveHead.second < 1)
        {
            isGameOver = true;
            break;
        }
        DQ.push_front(moveHead);
        snakeBody.insert(moveHead);

        auto it = find(apple.begin(), apple.end(), moveHead);
        if (it != apple.end())
        {
            apple.erase(it);
        }
        else
        {
            snakeBody.erase(DQ.back());
            DQ.pop_back();
        }
        currentHead = moveHead;

        if (curve.count(count))
        {
            if (curve[count] == 'D')
            {
                currentCurve = rightTurn[currentCurve];
            }
            else if (curve[count] == 'L')
            {
                currentCurve = leftTurn[currentCurve];
            }
        }
    }
    cout << count << endl;
}