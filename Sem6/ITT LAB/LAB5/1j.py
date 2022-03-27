s='AHYBDCSZ'
s_new=''
for i in s:
    p=ord(i)
    p+=3
    if(p>90):
        p-=26
    s_new+=chr(p)
print(s_new)
