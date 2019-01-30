try:
    while True:
        s = input()
        while True:
            if "BUG" in str(s):
                s2 = ""
                for a in s.split("BUG"):
                    s2+=a
                s = s2
            else:
                print(s)
                break
except:
    exit()

