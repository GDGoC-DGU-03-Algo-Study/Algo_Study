N, M, B = map(int, input().split())

# 입력을 평탄화하여 리스트에 저장
total_list = []
for _ in range(N):
    total_list.extend(map(int, input().split()))

max_num = max(total_list)
min_num = min(total_list)

min_cal = float('inf')  # 최솟값을 큰 수로 초기화
floor = 0

# 가능한 높이 범위 내에서 반복
for target_height in range(min_num, max_num + 1):
    remove_blocks = 0  # 제거해야 하는 블록 수
    add_blocks = 0     # 추가해야 하는 블록 수

    # 모든 높이를 순회하며 블록 추가/제거 계산
    for height in total_list:
        if height > target_height:
            remove_blocks += (height - target_height)
        elif height < target_height:
            add_blocks += (target_height - height)

    # 인벤토리에 있는 블록 수로 추가가 가능한지 확인
    if add_blocks > B + remove_blocks:
        continue  # 블록이 부족하면 건너뛴다

    # 총 시간 계산: 블록 제거는 2초, 추가는 1초
    cal = (remove_blocks * 2) + add_blocks

    # 최소 시간 갱신 및 최적의 높이 선택
    if cal < min_cal or (cal == min_cal and target_height > floor):
        min_cal = cal
        floor = target_height

print(min_cal, floor)