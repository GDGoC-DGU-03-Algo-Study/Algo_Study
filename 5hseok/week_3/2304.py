N = int(input())

hash_list = []
width = 0

for _ in range(N):
    L, H = map(int, input().split())
    hash_list.append([L, H])

hash_list = sorted(hash_list)

max_index = max(range(len(hash_list)), key=lambda i: hash_list[i][1])
temp_h = hash_list[0][1]
for i in range(max_index):
    # 만약 다음 기둥이 지금 기둥보다 크면 , 우선 지금 기둥을 더하고 기둥 높이 갱신
    if hash_list[i+1][1] > temp_h:
        width += temp_h * (hash_list[i+1][0] - hash_list[i][0])
        temp_h = hash_list[i+1][1]
    else:
        width += temp_h * (hash_list[i+1][0] - hash_list[i][0])

width += hash_list[max_index][1]

temp_h=hash_list[-1][1]

for i in range(N-1, max_index, -1):
    # 만약 다음 기둥이 지금 기둥보다 크면
    if hash_list[i - 1][1] > temp_h:
        width += temp_h * (hash_list[i][0] - hash_list[i-1][0])
        temp_h = hash_list[i - 1][1]
    else:
        width += temp_h * (hash_list[i][0] - hash_list[i-1][0])
print(width)