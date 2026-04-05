with open("input.txt") as f:

    joltage = 0
    for line in f:
        maxsum = -1

        bank = line.strip()
        for i in range(len(bank)-1):
            for j in range(i+1, len(bank)):
                if int(bank[i] + bank[j]) > maxsum:
                    maxsum = int(bank[i] + bank[j])

        joltage += maxsum

    print(joltage)