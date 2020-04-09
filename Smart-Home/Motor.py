#coding=utf8
'''***********************************************
*模块： 电机及灯光控制模块
*主要功能： 1.控制电机的转动
           2.控制电机的状态灯光
***********************************************'''
import binascii
import time
import mysqlcon as mc
'''***********************************************
*函数： op_motor
*主要功能： 电机启动和停止
*相关参数： ser 发送端口连接句柄
           op  选择启动或停止操作
           num 选择电机号
***********************************************'''
def opp_motor(ser,op,num):
    con=mc.mysqlconnect()
    cursor=con.cursor()

    if op=='open':
        senddata='ccee'+num+'090b00000000000000000000ff'
        senddata=binascii.b2a_hex(senddata)
        try:
            ser.write(senddata)
            cursor.execute('update sensorinfo set motor%s_status=%s where id=0',(num[:-1],'OPEN'))
            con.commit()
            print 'motor '+num+' start success!'
        except:
            print 'motor '+num+' start failed!'

    if op=='close':
        senddata='ccee'+num+'090b00000000000000000000ff'
        senddata=binascii.b2a_hex(senddata)
        try:
            ser.write(senddata)
            cursor.execute('update sensorinfo set motor%s_status=%s where id=0',(num[:-1],'CLOSE'))
            con.commit()
            print 'motor '+num+' close success!'
        except:
            print 'motor '+num+' close failed!'
    cursor.close()
    con.close() 
'''***********************************************
*函数： status_motor
*主要功能： 电机状态灯光控制
*相关参数： ser 发送端口连接句柄
           data 电机回复数据
*功能： 1.当电机回复数据为EE CC NO 09 DD 09时
         开启LED1灯
       2.当电机回复数据为EE CC NO 09 DD 0b时
         关闭LED1灯
        LED1灯为电机状态灯，电机开启时为亮状态
***********************************************'''
def status_motor(ser,data):
    num=data[4:6]
    if data[10:12]=='09':
        senddata='ccee'+num+'090100000000000000000000ff'
        senddata=binascii.b2a_hex(senddata)
        ser.write(senddata)
        print 'motor ',num,' light open!'
    if data[10:12]=='0b':
        senddata='ccee'+num+'090200000000000000000000ff'
        senddata=binascii.b2a_hex(senddata)
        ser.write(senddata)
        print 'motor ',num,' light close!'
'''***********************************************
*函数： time_motor
*主要功能： 电机在开启设定的时间后自动关闭
*相关参数： ser 发送端口连接句柄
           num 选择电机
           set_time 自动关闭延迟时间
***********************************************'''
def time_motor(ser,num,set_time):
    opp_motor(ser,'open',num)
    time.sleep(set_time)
    opp_motor(ser,'close',num)

