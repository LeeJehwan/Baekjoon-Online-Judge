s = list()
try:
    word = 0
    while True:
        s = input().split()
        for x, i in zip(s, range(len(s))):
            if x == '<br>':
                print()
                word = 0
            elif x == '<hr>':
                if word == 0:
                    print('-'*80)
                else:
                    print()
                    print('-' * 80)
                word = 0
            else:
                if word != 0:
                    word += 1
                word += len(x)
                if word > 80:
                    print()
                    print(x, end =" ")
                    word = len(x)
                else:
                    print(x, end=" ")

except:
    exit()