from itertools import combinations as cb

def cal_dist(pos1, pos2):
    return abs(pos1[0]-pos2[0]) + abs(pos1[1]-pos2[1])

n, m = map(int, input().split())
city = list()
for i in range(n):
    city.append(list(map(int, input().split())))

house = list()
chicken = list()
for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            house.append([i, j])
        elif city[i][j] == 2:
            chicken.append([i, j])

ans = 100000000000
for comb in cb(chicken, m):
    tmp_sum = 0
    for x in house:
        tmp_sum += min((cal_dist(x, pos)) for pos in comb)
    ans = min(ans, tmp_sum)
    
print(ans)
