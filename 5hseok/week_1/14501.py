def recursive(day, profit):
    # 종료 조건: 현재 날짜가 N을 초과하면 탐색 종료
    if day >= N:
        return profit

    # 상담을 하지 않는 경우 -> 다음 날로 이동
    profit_without = recursive(day + 1, profit)

    # 상담을 선택하는 경우 -> 현재 상담이 가능한지 확인
    profit_with = 0
    if day + t_list[day] <= N:
        profit_with = recursive(day + t_list[day], profit + p_list[day])

    # 두 경우 중 최대값 반환
    return max(profit_without, profit_with)


# 입력 처리
N = int(input())
t_list = []
p_list = []

for _ in range(N):
    t, p = map(int, input().split())
    t_list.append(t)
    p_list.append(p)

# 재귀 탐색 시작
max_profit = recursive(0, 0)

# 결과 출력
print(max_profit)


# 이걸 백트래킹으로 풀면 이렇게 된다.

# def backtrack(day, profit):
#     global max_profit
#
#     # 종료 조건: 현재 날짜가 N을 초과하면 탐색 종료
#     if day >= N:
#         max_profit = max(max_profit, profit)
#         return
#
#     # 상담을 하지 않는 경우 -> 다음 날로 이동
#     backtrack(day + 1, profit)
#
#     # 상담을 선택하는 경우 -> 현재 상담이 가능한지 확인
#     if day + t_list[day] <= N:
#         backtrack(day + t_list[day], profit + p_list[day])
#
#
# # 입력 처리
# N = int(input())
# t_list = []
# p_list = []
#
# for _ in range(N):
#     t, p = map(int, input().split())
#     t_list.append(t)
#     p_list.append(p)
#
# # 최대 이익 변수 초기화
# max_profit = 0
#
# # 백트래킹 탐색 시작
# backtrack(0, 0)
#
# # 결과 출력
# print(max_profit)