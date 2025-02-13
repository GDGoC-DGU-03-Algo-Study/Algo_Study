from collections import deque

N, M = map(int, input().split())
campus = [list(input().strip()) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    for j in range(M):
        if campus[i][j] == 'I':
            start_x, start_y = i, j
            break

def bfs(start_x, start_y):
    queue = deque([(start_x, start_y)])
    visited = [[False] * M for _ in range(N)]
    visited[start_x][start_y] = True
    people_count = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):  # 상하좌우 이동
            nx, ny = x + dx[i], y + dy[i]

            # 범위를 벗어나지 않고, 방문하지 않았으며, 벽이 아닌 곳만 탐색
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and campus[nx][ny] != 'X':
                visited[nx][ny] = True
                queue.append((nx, ny))

                # 사람이 있는 곳면 카운트 증가
                if campus[nx][ny] == 'P':
                    people_count += 1

    return people_count

result = bfs(start_x, start_y)

print(result if result > 0 else "TT")