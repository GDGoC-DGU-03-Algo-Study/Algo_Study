N = int(input())

check_field = [-1] * N
check_flag = 0

# 놓을 수 있는 지 확인
def check_queen(row, col):
    # field의 인덱스는 행, 값은 열
    # 어차피 한 행(가로)에는 하나의 Queen만 놓을 수 있으니까
    for i in range(row):
        if row-i == abs(col-check_field[i]) or check_field[i]==col:
            return False
    return True

# 놓는 함수
def batch_queen(row):
    global check_flag
    if row == N:
        check_flag += 1
        return

    for i in range(N):
        if check_queen(row, i):
            check_field[row] = i
            batch_queen(row+1)
            check_field[row] = -1

batch_queen(0)
print(check_flag)