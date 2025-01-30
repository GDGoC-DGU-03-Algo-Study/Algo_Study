N = int(input())
K = int(input())

init_count = 0
init_dirac = 0 # 0이 동, 1이 서, 2가 남, 3이 북
snack_stack = [[1,1]] # 뱀 위치

apple_loc = []

for _ in range(K):
    l,r = map(int, input().split())
    apple_loc.append([l,r])
L = int(input())
chance_and_dir = []
for _ in range(L):
    x,c = input().split()
    chance_and_dir.append([int(x), c])

def move(now_count, dirac):
    # 방향을 바꿀 때가 되었다면
    # 머리를 다음칸에 위치시킨다.
    now_location = snack_stack[-1]
    if dirac == 0:
        new_location = [now_location[0], now_location[1]+1]
    elif dirac == 1:
        new_location = [now_location[0], now_location[1]-1]
    elif dirac == 2:
        new_location = [now_location[0]+1, now_location[1]]
    else:
        new_location = [now_location[0]-1, now_location[1]]

    snack_stack.append(new_location)

    # 이동한 위치 반환
    return now_count, new_location

def check_game_over(head_location):
    # 머리의 위치가 벽에 닿았거나 혹은 자기 자신의 몸에 닿았는 지 검사한다.
    # 맞으면 종료
    if head_location[0] == 0 or head_location[0] == N+1 or head_location[1] == 0 or head_location[1]==N+1 or head_location in snack_stack[:-1]:
        # 자기 몸에 닿았을 경우
            return True
    # 아니면 카운트 하나 늘리고 게임 속행
    return False

def check_apple(head_location):
    # 들어온 위치에 사과가 있는 지 확인하고
    if head_location in apple_loc:
        # 있으면 true 반환
        return True
    # 없으면 false 반환
    return False

def action_with_apple(apple_location):
    # 해당 위치의 사과를 지움
    apple_loc.pop(apple_loc.index(apple_location))

def action_without_apple():
    # 사과가 없으니까
    # 꼬리 칸을 비운다.
    snack_stack.pop(0)

def change_dirac(dirac, left_or_right):
    # 방향을 바꿈
    if dirac == 0 and left_or_right=="L":
        new_dirac = 3
    elif dirac == 0 and left_or_right=="D":
        new_dirac = 2
    elif dirac == 1 and  left_or_right=="L":
        new_dirac = 2
    elif dirac == 1 and  left_or_right=="D":
        new_dirac = 3
    elif dirac == 2 and  left_or_right=="L":
        new_dirac = 0
    elif dirac == 2 and  left_or_right=="D":
        new_dirac = 1
    elif dirac == 3 and  left_or_right=="L":
        new_dirac = 1
    else: # dirac == 3 and left_or_right=="R"
        new_dirac = 0
    return new_dirac

def game(now_count, dirac):
    while(True):
        # print("now count:", now_count, "dirac:" , dirac)
        # print("now snack", snack_stack)
        now_count+=1
        # print(now_count)
        now_count, new_head_location = move(now_count, dirac)
        # print("new_head_location", new_head_location)
        # print("Refactor snack", snack_stack)
        if check_game_over(new_head_location):
            # print("Game over")
            break
        if apple_loc != [] and check_apple(new_head_location):
            action_with_apple(new_head_location)
            # print("Move snack: ", snack_stack)
        else:
            action_without_apple()
            # print("Move snack: ", snack_stack)
        if chance_and_dir != [] and now_count == chance_and_dir[0][0]:
            # print("Turn!")
            dirac = change_dirac(dirac, chance_and_dir[0][1])
            chance_and_dir.pop(0)
    print(now_count)


game(init_count, init_dirac)