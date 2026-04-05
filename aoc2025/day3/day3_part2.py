with open("input.txt") as f:

    joltage = 0
    for line in f:
        bank = line.strip()
        l = len(bank)
        dp = [[0 for i in range(l+1)] for j in range(l+1)]

        for i in range(1, l + 1):
            for j in range(1, i):
                dp[i][j] = max(dp[i-1][j], int(bank[l - i] + (str(dp[i-1][j-1]) if j > 1 else '')))
            dp[i][i] = int(bank[l - i:])

        joltage += dp[l][12]

    print(joltage)