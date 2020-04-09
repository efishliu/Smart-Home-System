#coding=utf8
'''***********************************************
*模块： 程序主入口
***********************************************'''
import time
import string
import mysqlcon as mc
import Coordinator as ci
import Motor as mt
import TempAndHum as th
import PhotoResisitor as pr
import Touch as tc
import thread
from  Display import *

'''***********************************************
*函数： dealdata
*主要功能： 1.实时接收数据并存入数据库
           2.接收到有效数据后进行状态更新
***********************************************'''
def dealdata():
    set_temp_hum={}
    set_temp_hum['min_temp']=input("please input min start temp:\n")
    set_temp_hum['min_hum']=input("please input min start hum:\n")
    
    #设置温度值更新
    con=mc.mysqlconnect()
    cursor=con.cursor()
    cursor.execute('update sensorinfo set set_temp=%s,set_hum=%s where id=0',(set_temp_hum['min_temp'],set_temp_hum['min_hum']))
    con.commit()
    cursor.close()
    con.close()

    flag=True
    sleep_flag=False
    ser=ci.CoorConnectPc()
    while 1 :
        data=ci.ReadPort(ser)

        if data[8:10]!='aa':
            #温湿度模块
            if data[6:8]=='03':
                now_temp_hum=th.temp_hum_store(data)
                print 'now temp hum:',now_temp_hum['temp'],now_temp_hum['hum']
                print 'set temp hum:',set_temp_hum['min_temp'],set_temp_hum['min_hum']
                if flag==True:
                    th.judge_temp_hum(ser,now_temp_hum,set_temp_hum)

            #光敏模块
            if data[6:8]=='02':
                light=pr.photores_store(data)
            #智能开关打开且不是睡眠模式
                if flag==True and sleep_flag==False:
                    pr.dimming(ser,light)
            
            #触摸模块
            #有触摸时
            if flag==True and data[6:8]=='0e' and data[10:12]=='01':
                tc.touch(ser,data[8:10],flag,sleep_flag)
                if sleep_flag==True:
                    #关闭全部灯
                    pwm.led_light(ser,'00')
                    #关棚帘
                    mt.time_motor(ser,'03',3)
            
            #电机模块
            if flag==True and data[6:8]=='09':
                if data[8:9]=='dd':
                    mt.status_motor(ser,data)
'''***********************************************
*函数： main
*主要功能： 程序主入口函数
***********************************************'''
if __name__ == '__main__':
    #多线程处理数据函数
    thread.start_new_thread(dealdata,())
    #图形界面
    thread.start_new_thread(windows,())
    time.sleep(10000)  