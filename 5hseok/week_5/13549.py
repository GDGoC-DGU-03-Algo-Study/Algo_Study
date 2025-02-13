from collections import deque

N, K = map(int, input().split())

def bfs(N, K):
    if N >= K:
        return N - K

    queue = deque([N])
    visited = [-1] * 100001
    visited[N] = 0

    while queue:
        x = queue.popleft()

        if 2 * x <= 100000 and visited[2 * x] == -1:
            visited[2 * x] = visited[x]
            queue.appendleft(2 * x)

        if x - 1 >= 0 and visited[x - 1] == -1:
            visited[x - 1] = visited[x] + 1
            queue.append(x - 1)

        if x + 1 <= 100000 and visited[x + 1] == -1:
            visited[x + 1] = visited[x] + 1
            queue.append(x + 1)

        if visited[K] != -1:
            return visited[K]

print(bfs(N, K))