from collections import deque
import sys

# sys.stdin = open("input.txt", "r")

# NOTE: n^4 n이 8보다 작은 수로 2초 안에 해결 가능

n, m = map(int, input().split())
load_map = [[] for _ in range(n)]
viruses = []

blank_count = 0

for i in range(n):
    load_map[i] = list(map(int, input().split()))
    for j in range(m):
        if load_map[i][j] == 0:
            blank_count += 1
        if load_map[i][j] == 2:
            viruses.append((i, j))


def get_safe_area():
    safe_area = blank_count - 3
    queue = deque(viruses.copy())
    visited = [[False] * m for _ in range(n)]

    while queue:
        x, y = queue.popleft()
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if (
                0 <= nx < n
                and 0 <= ny < m
                and not visited[nx][ny]
                and load_map[nx][ny] == 0
            ):
                visited[nx][ny] = True
                safe_area -= 1
                queue.append((nx, ny))

    return safe_area


def set_walls(count, current):
    if count == 3:
        return get_safe_area()
    result = 0
    for position in range(current, n * m):
        i, j = position // m, position % m
        if load_map[i][j] == 0:
            load_map[i][j] = 1
            result = max(result, set_walls(count + 1, i * m + j + 1))
            load_map[i][j] = 0

    return result


print(set_walls(0, 0))
