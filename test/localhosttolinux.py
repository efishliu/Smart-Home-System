#encoding=utf8
import pymysql
import time
import pandas as pd

def linux_mysqlconnect():
    con=pymysql.connect(
        host='59.110.159.69',
        port=3306,
        user='root',
        passwd='root',
        database='zhaopin',
        charset='utf8',
    )
    return con

def mysqlconnect():
    con=pymysql.connect(
        host='localhost',
        port=3306,
        user='root',
        passwd='liugang666',
        database='zhaopin',
        charset='utf8',
    )
    return con
if __name__ == '__main__':
    linux_con=linux_mysqlconnect()
    linux_cursor=linux_con.cursor()
    local_con=mysqlconnect()
    local_cucursor=local_con.cursor()
    data=pd.read_sql('select * from collect2 where workcity="北京" and company_industry="计算机软件"',local_con)

    #data=pd.read_sql('select temp,hum,addtime from temp_hum',local_con)
    #print data.ix[0]
    #print data.ix[0].temp
    '''for i in range(279):
        linux_cursor.execute('insert into temp_hum(temp,hum,addtime) values(%s,%s,%s)',(str(data.ix[i].temp),str(data.ix[i].hum),str(data.ix[i].addtime)))
        linux_con.commit()
        #print str(a['temp']),str(a['hum']),str(a['addtime'])
        #print d['temp']
        print 'ok'
        '''
    for i in range(105):
        linux_cursor.execute('insert into photores(illumination,addtime) values(%s,%s)',(str(data.ix[i].illumination),str(data.ix[i].addtime)))
        linux_con.commit()
    print 'ok'