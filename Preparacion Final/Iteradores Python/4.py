#PROBLEMA 4
import math
def solution(it):
    sum = 0
    for i in range(it):
        sum += (math.pow(-1,i)) / ((2 * i) + 1)
    return sum


if __name__ == "__main__":
    n = int(input())
    print(solution(n))