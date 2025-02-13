N, M = map(int, input().split())

check_hash = {}
result_list = []
for _ in range(N+M):
    tmp = input()
    if tmp in check_hash.keys():
        result_list.append(tmp)
        continue
    check_hash[tmp] = 1
print(len(result_list))
for string in sorted(result_list):
    print(string)


