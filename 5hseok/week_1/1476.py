# 입력 처리
num_list = input().split(' ')
E, S, M = int(num_list[0]), int(num_list[1]), int(num_list[2])

# 각 주기의 최대값
E_cycle, S_cycle, M_cycle = 15, 28, 19

year = 1
# (year - E) % 15 == 0 → 15n + E에서 n을 찾고 싶다면 E를 빼고 15로 나눈 나머지가 0이어야 함.
# 다른 S나 M도 마찬가지
while True:
    # E, S, M 조건을 만족하는지 확인
    if (year - E) % E_cycle == 0 and (year - S) % S_cycle == 0 and (year - M) % M_cycle == 0:
        print(year)
        break
    year += 1


