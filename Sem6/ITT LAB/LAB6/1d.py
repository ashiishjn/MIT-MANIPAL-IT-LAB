body = open("body.txt", "r+")
name = open("names.txt", "r+")
bdy = body.read()
for nam in name:
  print(nam)
  mail  = "Hello " + nam.strip() + "\n" + bdy
  wri = open(nam.strip()+".txt", "w")
  wri.write(mail)