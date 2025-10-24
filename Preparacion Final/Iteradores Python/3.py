#PROBLEMA 3
import math

def isSuperSquare(n):
    while(int(n / 10) > 0):
        s = str(n)
        tmp = 0
        for i in range(len(s)):
            tmp += math.pow(int(s[i]), 2)
        n = int(tmp)
    return n == 1

if __name__ == "__main__":
    n = int(input())
    print(isSuperSquare(n))