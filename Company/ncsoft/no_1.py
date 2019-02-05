#coding=utf-8

def solution(city):
    cost = [[0]*len(city[0]) for _ in range(len(city))]
    y_ = len(city)
    x_ = len(city[0])
    queue = []
    for i in range(y_):
        for j in range(x_):
            if city[i][j] == 0 :
                queue.append([i,j])
            else :
                cost[i][j] = 250001

    while len(queue) != 0:
        index = queue.pop(0)
        y = index[0]
        x = index[1]

        if y > 0 and city[y-1][x] != 0 and cost[y][x] + 1 < cost[y-1][x]:
            cost[y-1][x] = cost[y][x] + 1
            queue.append([y-1,x])
        if x > 0 and city[y][x-1] != 0 and cost[y][x] + 1< cost[y][x-1]:
            cost[y][x-1] = cost[y][x] + 1
            queue.append([y,x-1])
        if y < y_-1 and city[y+1][x] != 0 and cost[y][x] + 1< cost[y+1][x]:
            cost[y+1][x] = cost[y][x] + 1
            queue.append([y+1,x])
        if x < x_-1 and city[y][x+1] != 0 and cost[y][x] + 1 < cost[y][x+1]:
            cost[y][x+1] = cost[y][x] + 1
            queue.append([y,x+1])

    answer = cost
    return answer

def PrintCity(city):
    x = len(city[0])
    y = len(city)
    for i in range(y):
        one_row = ""
        for j in range(x):
            one_row += str(city[i][j]) + " "
        print(one_row)

if __name__ == "__main__":

    test_case = int(input())

    for _ in range(test_case):
       size = input()
       y = size[0]
       x = size[1]
       city_ = [[0]*x for _ in range(y)]
       for i in range(y):
           tmp = input()
           for j in range(x):
               city_[i][j] = tmp[j]
       print("-"*20)
       PrintCity(city_)
       print("-"*10)
       PrintCity(solution(city_))
       print("-"*20)


# 마트와 아파트로 이루어진 m X n 행렬 안에서 각 아파트로부터 마트로 가는 최단거리를 다 구하는 문제 (마트 = 0, 아파트 = 1)
# 1 < m,n <= 500
# input으로 마트와 아파트로 이루어진 city가 주어진다.
