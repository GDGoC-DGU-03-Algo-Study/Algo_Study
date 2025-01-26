N, S = map(int, input().split())

num_list = list(map(int, input().split()))
count = 0
stack = []

def check(num):
    if num==S:
        return True

    return False
# DFS
def dfs(index):
    global count
    global stack

    if index >= N:  # 범위를 벗어나면 종료
        return

    # 현재 숫자를 포함하는 경우
    stack.append(num_list[index])
    if check(sum(stack)):
        count += 1
    dfs(index + 1)
    stack.pop()

    # 현재 숫자를 포함하지 않는 경우
    dfs(index + 1)

dfs(0)

print(count)