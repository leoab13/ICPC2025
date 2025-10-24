#PROBLEMA 5
def piramidOfNumbers(n):
    c = 0
    for i in range(0, n):
        for j in range(0, i + 1):
            c += 1
            print(c, end=" ")
        print()
    return

if __name__ == "__main__":
    n = int(input())
    piramidOfNumbers(n)