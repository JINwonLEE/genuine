def getFiles(n, capacity, files, index):
    if index == n:
        return 0
    rest = getFiles(n, capacity, files, index+1)
    choose = 0

    if capacity >= files[index] :
        choose = getFiles(n, capacity - files[index], files, index+1) + 1

    return max(rest, choose)

def solution(n,capacity,files):
    answer = 0
    for i in range(n):
        answer += getFiles(len(files), capacity, files, 0)
    return answer
