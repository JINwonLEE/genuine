#coding=utf-8
def isPal(p):
    length = len(p)
    start = 0
    end = length-1
    while start < end :
        if p[start] != p[end]:
            return False
        start += 1
        end -= 1
    return True

def solution(plain):
    answer = 0
    if isPal(plain) == True:
        return len(plain)

    if len(plain) % 2 == 0:
	for i in range(len(plain)+1, 2*len(plain) + 2):
            if i == 2 * len(plain) + 1 :
                answer = i
                return answer
            else :
                comp = plain + plain[:i-len(plain)][::-1]
                if isPal(comp) == True:
                    answer = len(comp)
                    break
    else :
        for i in range(len(plain)+1, 2*len(plain)):
            if i == 2*len(plain) - 1:
                answer = i
                return answer
            else :
                comp = plain + plain[:i-len(plain)][::-1]
                if isPal(comp) == True:
                    answer = len(comp)
                    break

    return answer


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

# 팰렌듈롬인것을 체크하고 그것이 아니면 최소 몇개를 추가해서 팰렌드롬을 만들 수 있는가 ? 그 펠렌드롬의 길이를 구하시오.
# solution : 팰린듈롬의 중심(실제 원소이거나 아니면 두 원소 사이) 뒤부터 한개씩 차례차례 비교하면서 중심을 오른쪽으로 1씩 옮겨가면서 비교하면 된다
