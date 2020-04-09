#encoding=utf-8
import serial
import time
import string  
import binascii 
import pymysql
import pandas as pd

con=pymysql.connect(
    host='localhost',
    port=3306,
    user='root',
    passwd='liugang666',
    database='sensor',
    charset='utf8',
)
cursor = con.cursor()

ser = serial.Serial(
port='COM3',
baudrate=115200,
bytesize = 8,
stopbits = 1,
parity = 'N',
timeout=1,
)

data = ''
while 1:
    data = str(binascii.b2a_hex(ser.read(16)))
    if (data)!='':
        print data
        if data[4:10]=='010301':
            xh=float(int(data[10:12],16))
            xl=float(int(data[12:14],16))
            temp=(xh*256+xl)/100
            xh=float(int(data[14:16],16))
            xl=float(int(data[16:18],16))
            hum=(xh*256+xl)/100
            print 'tem' + str(temp)
            print 'hum' + str(hum)
            cursor.execute('insert into temp_hum(temp,hum,addtime) values(%s,%s,%s)',(str(temp),str(hum),time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
            con.commit()





        