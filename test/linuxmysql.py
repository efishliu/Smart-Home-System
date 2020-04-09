#encoding=utf8
import pymysql
import time


def linux_mysqlconnect():
    con=pymysql.connect(
        host='59.110.159.69',
        port=3306,
        user='root',
        passwd='liugang666',
        database='sensor',
        charset='utf8',
    )
    return con
if __name__ == '__main__':
    con=linux_mysqlconnect()
    cursor=con.cursor()
    cursor.execute('insert into temp_hum(temp,hum,addtime) values(%s,%s,%s)',('28','39',time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
    con.commit()
    cursor.close()
    con.close()

    print 'ok'