def is_invalid(id: str):
    for i in range(1, len(id)//2+1):
        invalid = True
        for j in range(0, len(id)-i, i):
            if id[j:j+i] != id[j+i:j+2*i]:
                invalid = False
                break
        if invalid:
            return True 
    return False

with open("input.txt") as f:
    content = f.read()

    inv_sum = 0

    for id_range in content.split(','):
        start, end = map(int, id_range.split('-'))
        print(f'Checking range {start}-{end}')
        for i in range(start, end + 1):
            id_str = str(i)
            if is_invalid(id_str):
                print(f'{id_str} is invalid!')
                inv_sum += i
                
    print(inv_sum)