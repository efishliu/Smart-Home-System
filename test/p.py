#encoding=utf-8
import serial
import time
import string  
import binascii 
import pymysql


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
        if data[4:10]=='010201':
            ph=float(int(data[10:12],16))
            pl=float(int(data[12:14],16))
            p=ph*256+pl
            print p
            cursor.execute('insert into photores(illumination,addtime) values(%s,%s)',(str(p),time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
            con.commit()
