# 1 -> 생성 2 -> 도넛 3 -> 8자 4 -> 막대

from collections import deque

# O(max(e, v))

def solution(edges):
    # 자기 자신을 가르키면 무조건 도넛
    doughnut, bar, eight = 0, 0, 0
    nodes = [[[], []] for _ in range(1000001)]
    # 특정 노드로 들어오는 정점이 나가는 정점과 같이 2개면 8자
    # 특정 노드로 들어오는 간선이 0 또는 1이면서 나가는 간선이 1이면 막대

    nodes[0][0].append(1)

    max_node = 1
    for edge in edges:
        nodes[edge[0]][1].append(edge[1])
        nodes[edge[1]][0].append(edge[0])
        max_node = max(max_node, edge[0], edge[1])

    created_node = -1
    for i in range(1, max_node + 1):
        if len(nodes[i][1]) >= 2 and len(nodes[i][0]) == 0:
            created_node = i
            break

    visited = [0] * 1000001
    for start_node in nodes[created_node][1]:

        queue = deque([start_node])

        max_visit = 0
        while queue:
            node = queue.popleft()
            for next_node in nodes[node][1]:
                visited[next_node] += 1
                max_visit = max(max_visit, visited[next_node])
                if visited[next_node] == 1 and next_node != start_node:
                  queue.append(next_node)

        if max_visit == 2:
            eight += 1
        elif visited[start_node] == 0:
            bar += 1
        else:
            doughnut += 1

    return [created_node, doughnut, bar, eight]


# edges = [[2, 3], [4, 3], [1, 1], [2, 1]]

# print(solution(edges))
