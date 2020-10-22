import heapq


def f(n):
    if n == 1:
        return 1
    return n + f(n - 1)

s1 = set()
s2 = set()

s1.add(1)
s2.add(2)

s1 = s1.difference(s2)
print(s1)

print(f(10))
