
#PROBLEMA 1
def solution(n):
    s1,s2 = 0 , 0
    s = str(n)
    for i in range(len(s)):
        if( i % 2 == 0):
            s1 += int(s[i])
        else:
            s2 += int(s[i])
    print (s1,s2)
    return s1 == s2

if __name__ == "__main__":
    n = input()
    print(solution(n))