with open("input.txt") as f:
    lines = f.readlines()

    data = []
    for line in lines:
        data.append([i for i in line.strip().split(' ') if len(i) > 0])
        print(data[-1])

    ans = 0
    for k in range(len(data[-1])):
        op = data[-1][k]

        sol = 1 if op == '*' else 0
        for i in range(len(data)-2, -1, -1):
            if op == '*':
                sol *= int(data[i][k])
            elif op == '+':
                sol += int(data[i][k])
        
        ans += sol

    print(ans)
        