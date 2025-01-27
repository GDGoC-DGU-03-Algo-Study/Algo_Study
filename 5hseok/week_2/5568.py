import itertools

N = int(input())
K = int(input())

num_list = []
result_set = set()

for _ in range(N):
    num_list.append(int(input()))
iters = itertools.permutations(num_list, K)
for data in iters:
    result_set.add(int(''.join(map(str, data))))

print(len(result_set))

