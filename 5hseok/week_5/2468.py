from collections import deque

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y, visited, rain_height):
    queue = deque([(x, y)])
    visited[x][y] = True

    while queue:
        cx, cy = queue.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and graph[nx][ny] > rain_height:
                visited[nx][ny] = True
                queue.append((nx, ny))

# 가능한 모든 강우량에 대해 탐색
min_height = min(map(min, graph))
max_height = max(map(max, graph))
max_safe_areas = 1  # 모든 지역이 잠기지 않는 경우

for rain_height in range(min_height, max_height + 1):
    visited = [[False] * N for _ in range(N)]
    safe_area_count = 0

    for i in range(N):
        for j in range(N):
            if not visited[i][j] and graph[i][j] > rain_height:
                bfs(i, j, visited, rain_height)
                safe_area_count += 1

    max_safe_areas = max(max_safe_areas, safe_area_count)

print(max_safe_areas)