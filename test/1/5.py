import pymysql
import pandas as pd
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
realtime_data_sql='select * from temp_hum group by addtime desc limit 10'
realtime_data=pd.read_sql(realtime_data_sql,con)
print realtime_data