s = "abcdefedcb"
l = len(s)
p=l-1
f=0
for i in range (int(l/2)):
  if(s[i] != s[p]):
    print("Not Palindrome")
    f=1
    break
  p-=1
if(f==0):
  print("Palindrome")