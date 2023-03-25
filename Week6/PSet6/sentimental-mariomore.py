while True:
 height = int(input("Height: "))

 if 1<= height <= 8:
     break

for row in range(1, height + 1):
    print(' ' * (height - row) + '#' * row + ' ' * 2 + '#' * row)