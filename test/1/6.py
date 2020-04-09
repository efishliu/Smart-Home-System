#coding=utf8

import pandas as pd
import pymysql
def mysqlconnect():
    con=pymysql.connect(
        host='localhost',
        port=3306,
        user='root',
        passwd='liugang666',
        database='sensor',
        charset='utf8',
    )
    return con
con=mysqlconnect()
realtime_data_sql='select temp,hum,addtime from temp_hum group by id desc limit 10'
realtime_data=pd.read_sql(realtime_data_sql,con)
print realtime_data
print '************'
print realtime_data['temp'][0]