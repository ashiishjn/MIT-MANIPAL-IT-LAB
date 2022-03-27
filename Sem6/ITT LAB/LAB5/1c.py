a=[[1,2],[4,5],[7,8]]
b=[[2,3,4,1],[5,6,7,8]]
c=[[0,0,0,0],[0,0,0,0],[0,0,0,0]]
sum=0
for i in range(3):
    for j in range(4):
        sum=0
        for k in range(2):
            sum+=a[i][k]*b[k][j]
        c[i][j]=sum
for i in range(3):
    for j in range(4):
        print (c[i][j])
