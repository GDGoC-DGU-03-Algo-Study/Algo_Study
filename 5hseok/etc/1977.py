M = int(input())
N = int(input())
result_list = []
for i in range(M, N+1):
    for j in range(1, i+1):
        if i / j == j:
            result_list.append(i)
            break
if len(result_list) == 0:
    print(-1)
else:
    print(sum(result_list))
    print(min(result_list))