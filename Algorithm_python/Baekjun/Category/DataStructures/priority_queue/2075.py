
# heapq 예시

import heapq
import sys

n = int(sys.stdin.readline())
heap = []

for _ in range(n):
    nums = list(map(int, sys.stdin.readline().split()))
    for num in nums:
        heapq.heappush(heap, num)

print(heapq.nlargest(n, heap)[-1])
# print(heap)
#
# sorted_heap = sorted(heap, reverse=False)
# print(sorted_heap)




# 역량인증에서 사용 못할 수 있음! Python 3.9 메뉴얼에 검색이 안됨
# priority queue 예시
# from queue import PriorityQueue
# import sys
#
# n = int(sys.stdin.readline())
#
# pq = PriorityQueue()
#
# for _ in range(n):
#     nums = list(map(int, sys.stdin.readline().split()))
#     for num in nums:
#         pq.put(num)
# pq.queue.sort(reverse=True)
# # print(pq.queue)
#
# print(pq.queue[n])
#
