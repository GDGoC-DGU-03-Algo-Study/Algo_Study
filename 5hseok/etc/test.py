import itertools

# 정수 배열이 주어졌을 때 목표 수가 되는 숫자쌍들을 출력하기
# combinations를 사용했다가 시간복잡도가 O(n^2)라 최적화 요구받음
# set 사용하니 중복 문제로 실패
# dict까진 왔는데 접근을 잘못해서 실패

import itertools

def solve(input_list, target_num):
    result = []
    input_dict = {}
    # key : input, value: 필요한 수
    for num in input_list:
        if input_dict.setdefault(num, 0.5) != 0.5:
            input_dict[num] += 1
        else:
            input_dict[num] = 1

    for num in input_list:
        if input_dict.setdefault(num, 0)> 0 and input_dict.setdefault(target_num-num, 0) > 0:
            result.append([num,target_num-num])
            input_dict[num] -= 1
            input_dict[target_num-num]

    return result

print(solve([1,2,2,3,3,4,5],5))
def solve_2(input_list, target_num):
    result = []
    num_counts = {}  # 각 숫자의 등장 횟수를 기록하는 딕셔너리

    # 숫자의 등장 횟수를 저장
    for num in input_list:
        num_counts[num] = num_counts.get(num, 0) + 1

    for num in input_list:
        complement = target_num - num  # 타겟을 만들기 위한 보완 수

        # 보완 수가 존재하고, 이미 처리한 쌍이 아니라면 결과에 추가
        if complement in num_counts:
            if num == complement and num_counts[num] > 1:  # 자기 자신과 짝이 되는 경우
                result.append([num, complement])
                num_counts[num] -= 2  # 두 번 사용했으므로 2 감소
            elif num != complement and num_counts[num] > 0 and num_counts[complement] > 0:
                result.append([num, complement])
                num_counts[num] -= 1
                num_counts[complement] -= 1

        # 이미 사용된 숫자는 딕셔너리에서 제거
        if num_counts.get(num, 0) <= 0:
            num_counts.pop(num, None)
        if num_counts.get(complement, 0) <= 0:
            num_counts.pop(complement, None)

    return result


# 테스트 케이스
print(solve_2([1, 2, 2, 3, 3, 4, 5], 5))