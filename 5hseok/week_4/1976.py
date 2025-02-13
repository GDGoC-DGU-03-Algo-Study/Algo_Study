import sys

def dfs(city, graph, visited):
    visited[city] = True
    for next_city in graph[city]:
        if not visited[next_city]:
            dfs(next_city, graph, visited)



input = sys.stdin.readline

N = int(input())
M = int(input())

graph = {i: [] for i in range(1, N + 1)}

for i in range(1, N + 1):
    connections = list(map(int, input().split()))
    for j in range(1, N + 1):
        if connections[j - 1] == 1:
            graph[i].append(j)

travel_plan = list(map(int, input().split()))

visited = [False] * (N + 1)
dfs(travel_plan[0], graph, visited)

if all(visited[city] for city in travel_plan):
    print("YES")
else:
    print("NO")
