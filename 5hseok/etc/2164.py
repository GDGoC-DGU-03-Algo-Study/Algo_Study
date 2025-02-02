import sys
from collections import deque
input = sys.stdin.readline()
N = int(input)
_deque = deque()
for i in range(N):
    _deque.append(i+1)
while len(_deque) != 1:
    _deque.popleft()
    _deque.append(_deque.popleft())
print(_deque.pop())

