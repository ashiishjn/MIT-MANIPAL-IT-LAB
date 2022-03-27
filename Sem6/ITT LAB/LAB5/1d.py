a=[[1,2,3],[4,5,6],[7,8,9]]
b=[[2,3,4],[5,6,7],[1,8,5]]
c=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(3):
    for j in range(3):
        c[i][j]=a[i][j]+b[i][j]
for i in range(3):
    for j in range(3):
        print (c[i][j])
