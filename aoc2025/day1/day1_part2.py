import math

with open("input.txt") as f:
    dial = 50
    password = 0

    for line in f:
        dir = line[0]
        steps = int(line[1:])

        if dir == 'R':
            if dial + steps >= 100:
                password += math.floor((dial + steps)/100)
            dial = (dial + steps) % 100
        elif dir == 'L':
            if dial - steps <= 0:
                password += (1 if dial > 0 else 0) + math.floor((steps - dial)/100)
            dial = (dial - steps) % 100

        print(f"Direction: {dir}, Steps: {steps}, dial: {dial} Password: {password}")
    
    print(f"Final Password: {password}")