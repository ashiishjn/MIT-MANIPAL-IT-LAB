list = ["HELLO", "WORLD", "THIS", "IS", "INDIA"]
l = len(list)
for i in range(l-1):
  for j in range(0,l-i-1):
    if(list[j]>list[j+1]):
      a=list[j]
      list.pop(j)
      list.insert(j+1,a)

print(list)