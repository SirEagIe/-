import sqlite3 as sql
import datetime as dt
import calendar, os, sys

connection = sql.connect(os.path.abspath(os.path.dirname(sys.argv[0])) + '\\app.db')
with connection:
    cursor = connection.cursor()
    cursor.execute("DELETE FROM `work_schedule`")
    connection.commit()