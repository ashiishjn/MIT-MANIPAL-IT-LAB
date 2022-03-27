def sum(a):
    if a <= 1:
        return 1
    else:
        return a+sum(a-1)
print(sum(5))
