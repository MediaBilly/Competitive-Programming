with open("input.txt") as f:
    reading = True
    fresh_ranges = []

    ans = 0
    for line in f:
        line_stripped = line.strip()

        # Check for empty line to switch to second part
        if line_stripped == "":
            reading = False
            continue

        if reading:
            idFrom, idTo = map(int, line_stripped.split("-"))
            fresh_ranges.append((idFrom, idTo))
        else:
            product_id = int(line_stripped)
            for idFrom, idTo in fresh_ranges:
                if idFrom <= product_id <= idTo:
                    ans += 1
                    break

    print(ans)