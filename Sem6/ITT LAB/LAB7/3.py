#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('test.db')
print ("Opened database successfully")
a=input("Enter Registeration Number")
cursor = conn.execute("SELECT * from STUDENT WHERE REG = " + a)
for row in cursor:
 print(row)
print ("Operation done successfully")
conn.close()
