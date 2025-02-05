import sys
from collections import deque

input = sys.stdin.readline

n, w, L = map(int, input().split())
truck_list = list(map(int, input().split()))

bridge_queue = deque([0] * w)
current_weight = 0
result = 0

while truck_list or current_weight > 0:
    result += 1

    finished_truck = bridge_queue.popleft()
    current_weight -= finished_truck

    if truck_list:
        if current_weight + truck_list[0] <= L:
            next_truck = truck_list.pop(0)
            bridge_queue.append(next_truck)
            current_weight += next_truck
        else:
            bridge_queue.append(0)
    else:
        bridge_queue.append(0)
print(result)