a=13
binary = 0
s=1
while a!=0:
    d=a%2
    binary=s*d+binary
    a=a//2
    s=s*10
print (binary)


a=78
octal = 0
s=1
while a!=0:
    d=a%8
    octal=s*d+octal
    a=a//8
    s=s*10
print (octal)


a=17845
hexa = ''
d=0
h=''
while a!=0:
    d=a%16
    match d:
        case 0 : h='0'
        case 1 : h='1'
        case 2 : h='2'
        case 3 : h='3'
        case 4 : h='4'
        case 5 : h='5'
        case 6 : h='6'
        case 7 : h='7'
        case 8 : h='8'
        case 9 : h='9'
        case 10 : h='A'
        case 11 : h='B'
        case 12 : h='C'
        case 13 : h='D'
        case 14 : h='E'
        case 15 : h='F'
    hexa=h+hexa
    a=a//16
print (hexa)
