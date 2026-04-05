with open("input.txt") as f:
    grid = []
    ans = 0

    for line in f:
        row = [x for x in line.strip()]
        grid.append(row)

    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            adj_count = 0
            if cell == '@':
                for di in [-1, 0, 1]:
                    for dj in [-1, 0, 1]:
                        if di == 0 and dj == 0:
                            continue
                        ni, nj = i + di, j + dj
                        if 0 <= ni < len(grid) and 0 <= nj < len(row):
                            if grid[ni][nj] == '@':
                                adj_count += 1
                if adj_count < 4:
                    ans += 1
    
    print(ans)