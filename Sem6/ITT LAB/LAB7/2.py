#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('test.db')
a=1
print ("Opened database successfully")
s_id = input("Enter Student ID ")
reg = input("Enter Registeration No.")
while a == 1:
    branch = input("Enter Branch ")
    if(branch == "IT" or branch == "CSE" or branch == "EEE"):
        break
    else:
        print("Branch should be IT, CSE or EEE")

while a == 1:
    sem = input("Enter Semester ")
    if(ord(sem) >=49 and ord(sem) <= 56):
        break
    else:
        print("Semester should be between 1 and 8")

while a == 1:
    sec = input("Enter Section ")
    if(sec == "A" or sec == "B" or sec == "C" or sec == "D"):
        break
    else:
        print("Section should be A, B, C or D")

while a == 1:
    cgpa = float(input("Enter CGPA "))
    if(cgpa >=0 and cgpa <= 10):
        break
    else:
        print("cgpa should be between 0 and 10")

email = input("Enter email ")

conn.execute("INSERT INTO STUDENT VALUES (" + s_id + " , " + reg + " , '" +branch+"' , "+sem+", '"+sec+"' , "+ str(cgpa)+", '"+email +"')");
conn.commit()
print ("Records created successfully")
conn.close()
