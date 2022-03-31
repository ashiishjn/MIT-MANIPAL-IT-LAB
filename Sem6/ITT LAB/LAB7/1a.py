#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('test.db')
print ("Opened database successfully")
conn.execute('''CREATE TABLE STUDENT
 (STUDENTID INT PRIMARY KEY NOT NULL,
 REG INT NOT NULL,
 BRANCH TEXT NOT NULL,
 SEMESTER INT NOT NULL,
 SECTION CHAR(5),
 CGPA REAL,
 email char(50));''')
print ("Table created successfully")
conn.close()
