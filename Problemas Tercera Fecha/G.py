import math
from sys import stdin

def sol(h1, h2, b):
    n = math.log((h2/h1),((b-1)/b))
    return int(round(n, 0))

if __name__ == '__main__':
    answer = ""
    cases = int(input())
    for i in range(0, cases):
        h1, h2, b = map(int, stdin.readline().split())
        answer += str(sol(h1,h2,b)) + "\n"
    print(answer[:-1])
