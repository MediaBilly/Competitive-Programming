with open("input.txt") as f:
    content = f.read()

    inv_sum = 0

    for id_range in content.split(','):
        start, end = map(int, id_range.split('-'))
        for i in range(start, end + 1):
            id_str = str(i)
            valid = True
            if len(id_str) % 2 == 0:
                valid = id_str[:len(id_str)//2] != id_str[len(id_str)//2:]
            
            if not valid:
                inv_sum += i
                
    print(inv_sum)