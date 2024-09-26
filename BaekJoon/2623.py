from collections import deque
import sys

# sys.stdin = open("input.txt", "r")

#NOTE: O(V + E) 

n, m = map(int, input().split())

member_children = [[] for _ in range(n + 1)]
member_parent_count = [0] * (n + 1)


for i in range(m):
    _, *orders = list(map(int, input().split()))

    for j in range(1, len(orders)):
        parent = orders[j - 1]
        child = orders[j]

        member_children[parent].append(child)
        member_parent_count[child] += 1

queue = deque([])

for i in range(1, n + 1):
    if member_parent_count[i] == 0:
        queue.append(i)

answer = []

while queue:
    cur = queue.popleft()
    answer.append(cur)

    for child in member_children[cur]:
        member_parent_count[child] -= 1
        if member_parent_count[child] == 0:
            queue.append(child)

print('0' if len(answer) != n else "\n".join(map(str, answer)))