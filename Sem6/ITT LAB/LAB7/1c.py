#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('test.db')
print ("Opened database successfully")
cursor = conn.execute("SELECT * from STUDENT ORDER BY CGPA DESC")
for row in cursor:
 print(row)
print ("Operation done successfully")
conn.close()

