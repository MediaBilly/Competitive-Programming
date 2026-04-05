def range_length(rng):
    start, end = rng
    return end - start + 1

def overlar_count(range1, range2):
    start1, end1 = range1
    start2, end2 = range2

    if end1 < start2 or end2 < start1:
        return 0

    overlap_start = max(start1, start2)
    overlap_end = min(end1, end2)

    return overlap_end - overlap_start + 1

with open("input_part2.txt") as f:
    fresh_ranges = set()
    ans = 0

    # Read all fresh ranges
    for line in f:
        line_stripped = line.strip()

        idFrom, idTo = map(int, line_stripped.split("-"))

        # Handle overlaps
        overlap_found = False
        while True:
            loop = False
            
            for existing_range in fresh_ranges:
                # Skip self-comparison
                if existing_range == (idFrom, idTo):
                    continue

                overlap_len = overlar_count(existing_range, (idFrom, idTo))
                if overlap_len > 0:
                    idFrom = min(idFrom, existing_range[0])
                    idTo = max(idTo, existing_range[1])
                    fresh_ranges.remove(existing_range)
                    fresh_ranges.add((idFrom, idTo))
                    loop = True
                    overlap_found = True
                    break

            if not loop:
                break

        if not overlap_found:
            fresh_ranges.add((idFrom, idTo))
        
    for rng in fresh_ranges:
        ans += range_length(rng)

    print(ans)