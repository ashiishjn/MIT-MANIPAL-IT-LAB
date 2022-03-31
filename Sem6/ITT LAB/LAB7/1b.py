#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('test.db')
print ("Opened database successfully")
conn.execute("INSERT INTO STUDENT VALUES (1, 191, 'IT', 6, 'A', 8.92, 'abc1@gmail.com' )");
conn.execute("INSERT INTO STUDENT VALUES (2, 192, 'IT', 6, 'B', 9.12, 'abc2@gmail.com' )");
conn.execute("INSERT INTO STUDENT VALUES (3, 193, 'CSE', 4, 'A', 7.25, 'abc3@gmail.com' )");
conn.execute("INSERT INTO STUDENT VALUES (4, 194, 'EEE', 4, 'A', 8.08, 'abc4@gmail.com' )");
conn.commit()
print ("Records created successfully")
conn.close()
