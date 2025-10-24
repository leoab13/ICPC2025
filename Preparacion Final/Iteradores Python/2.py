#PROBLEMA 2
import math

def solution(n):
    c = str(n)
    sum = 0
    for i in range(len(c)):
        sum += math.pow(int(c[i]), (i + 1))
    return sum == n

if __name__ == "__main__":
    n = int(input())
    print(solution(n))