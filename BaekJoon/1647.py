from collections import deque
import heapq
import sys

# sys.stdin = open("input.txt", "r")

# NOTE: n (heap 생성) + {log n * m} (edge 선택) * {m + n} (node 연결 여부 확인)
# NOTE: O(m * n + m * log n) => 시간 초과

n, m = map(int, input().split())

heap = []

for i in range(m):
    v, w, c = map(int, input().split())
    heapq.heappush(heap, (c, v, w))

adjacency_list = [[] for _ in range(n + 1)]


def check_load_duplicated(v, w):
    current = v
    visited = [False] * (n + 1)
    visited[current] = True

    queue = deque([current])
    while queue:
        current = queue.popleft()
        for next_node in adjacency_list[current]:
            if next_node == w:
                return True

            if visited[next_node]:
                continue

            visited[next_node] = True
            queue.append(next_node)

    return False


max_cost = 0
total_cost = 0
while heap:
    c, v, w = heapq.heappop(heap)
    if check_load_duplicated(v, w):
        continue
    max_cost = max(max_cost, c)
    total_cost += c

    adjacency_list[v].append(w)
    adjacency_list[w].append(v)

print(total_cost - max_cost)
