import sys
input = sys.stdin.readline

class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, num):
        self.heap.append(num)
        self._heapify_up(len(self.heap) - 1)

    def extract_max(self):
        if not self.heap:
            return 0
        if len(self.heap) == 1:
            return self.heap.pop()
        max_val = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return max_val

    def _heapify_up(self, index):
        parent = (index - 1) // 2
        if index > 0 and self.heap[index] > self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._heapify_up(parent)

    def _heapify_down(self, index):
        largest = index
        left, right = 2 * index + 1, 2 * index + 2
        if left < len(self.heap) and self.heap[left] > self.heap[largest]:
            largest = left
        if right < len(self.heap) and self.heap[right] > self.heap[largest]:
            largest = right
        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._heapify_down(largest)

N = int(input())
my_heap = MaxHeap()
print_list = []
for _ in range(N):
    order = int(input())
    if order == 0:
        print_list.append(my_heap.extract_max())
    else:
        my_heap.insert(order)

for number in print_list:
    print(number)
