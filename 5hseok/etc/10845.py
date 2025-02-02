
N = int(input())

result_queue = []

for _ in range(N):
    order = input()

    check = order[0]
    total_len = len(result_queue)
    #front
    if check == "f":
        if total_len != 0:
            print(result_queue[0])
            continue
        print(-1)
    # back
    elif check == "b":
        if total_len != 0:
            print(result_queue[-1])
            continue
        print(-1)
    # empty
    elif check == "e":
        if total_len != 0:
            print(0)
            continue
        print(1)    # size
    elif check == "s":
        print(total_len)
    # pop
    elif order == "pop":
        if total_len != 0:
            print(result_queue.pop(0))
            continue
        print(-1)
    else:
        number = int(order[5:])
        result_queue.append(number)



