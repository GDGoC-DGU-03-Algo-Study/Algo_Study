N, M = map(int, input().split())

hash_password = {}
for _ in range(N):
    site, password = map(str, input().split())
    hash_password[site]=password

for _ in range(M):
    print(hash_password[input()])
