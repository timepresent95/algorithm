import sys

# sys.stdin = open("input.txt", "r")

n, m = map(int, input().split())

ice = [list(map(int, input().split())) for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def check():
    visited = [[False] * m for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(m):
            if ice[i][j] > 0 and not visited[i][j]:
                cnt += 1
                stack = [(i, j)]
                visited[i][j] = True
                while stack:
                    x, y = stack.pop()
                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if (
                            0 <= nx < n
                            and 0 <= ny < m
                            and ice[nx][ny] > 0
                            and not visited[nx][ny]
                        ):
                            stack.append((nx, ny))
                            visited[nx][ny] = True
    return cnt


def melt():
    melt_level = [[0] * m for _ in range(n)]
    melt_cnt = 0
    for i in range(n):
        for j in range(m):
            if ice[i][j] == 0:
                continue

            melt_cnt += 1

            for k in range(4):
                ni, nj = i + dx[k], j + dy[k]
                if 0 <= ni < n and 0 <= nj < m and ice[ni][nj] == 0:
                    melt_level[i][j] += 1

    for i in range(n):
        for j in range(m):
            ice[i][j] = max(0, ice[i][j] - melt_level[i][j])

    return melt_cnt


year = 0
while True:
    if melt() == 0:
        print(0)
        break

    year += 1

    if check() >= 2:
        print(year)
        break
