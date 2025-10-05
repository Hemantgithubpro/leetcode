
def pacificAtlantic(heights):
    m = len(heights)
    n = len(heights[0])
    result = []

    # first both corners
    result.append([0, m - 1])
    result.append([n - 1, 0])

    # first try with bfs
    pacific_visited = set()
    atlantic_visited = set()

    # def bfs(start, visited):
    #     queue = [start]
    #     while queue:
    #         x, y = queue.pop(0)
    #         if (x, y) in visited:
    #             continue
    #         visited.add((x, y))
    #         for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
    #             nx, ny = x + dx, y + dy
    #             if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited and heights[nx][ny] >= heights[x][y]:
    #                 queue.append((nx, ny))

    # for i in range(m):
    #     bfs((i, 0), pacific_visited)
    #     bfs((i, n - 1), atlantic_visited)
    # for j in range(n):
    #     bfs((0, j), pacific_visited)
    #     bfs((m - 1, j), atlantic_visited)

    # dfs approach
    def dfs(x, y, visited):
        if (x, y) in visited:
            return
        visited.add((x, y))
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited and heights[nx][ny] >= heights[x][y]:
                dfs(nx, ny, visited)

    dfs(0, 0, pacific_visited)
    dfs(m - 1, n - 1, atlantic_visited)

    result = list(pacific_visited & atlantic_visited)
    return result