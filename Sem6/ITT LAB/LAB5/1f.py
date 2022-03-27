def fibo(a):
    if(a==0):
        return 0
    elif(a==1):
        return 1
    else:
        return fibo(a-1)+fibo(a-2)

for i in range(10):
    print (fibo(i))
