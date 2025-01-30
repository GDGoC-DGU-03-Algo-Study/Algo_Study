import itertools
N = int(input())

# 팀을 나누는 모든 경우의 수를 구하고
min_abi = float('inf')

stat_list = []

for _ in range(N):
    tmp = []
    for e in map(int, input().split()):
        tmp.append(e)
    stat_list.append(tmp)

for person in itertools.combinations(range(N), N//2):
    team_1 = []
    team_2 = []
    for i in range(N):
        if i in person:
            team_1.append(i)
        else:
            team_2.append(i)

    # 합 구하기
    team_1_total = 0
    team_2_total = 0

    for i in team_1:
        for j in team_1:
            team_1_total += stat_list[i][j]

    for i in team_2:
        for j in team_2:
            team_2_total += stat_list[i][j]


    if min_abi > abs(team_2_total - team_1_total):
        min_abi = abs(team_2_total - team_1_total)

print(min_abi)