## 概述
Smart-Home是一个模拟的智能家居系统，通过SHT10 单片数字温湿度、光敏、触摸传感器来监测环境，将数据保存到本地和云端，
并通过Web端和PC端进行可视化展示，最终能够根据传感器的采集的数据进行智能化展示和控制。  

## 工具和环境  
*  SHT10单片传感器，IAR集成开发环境，串口助手
*  Django, python2.7, pymysql,Tkinter,matplotlib,mysql  

## 概要设计
* **系统架构**  
<div align=center>
<img src="https://github.com/efishliu/Smart-Home-System/blob/master/image/system.jpg?raw=true" width = 50% height = 50% />
</div>  

* **数据库设计：**[Mysql-table.txt](https://github.com/efishliu/Smart-Home-System/blob/master/Mysql-table.txt)  

| 表名 | 表的描述 | 表名 | 表的描述 | 
|:----:|:----:|:----:|:----:|
| sensorinfo | 当前各传感器状态表 | Temp_hum | 温湿度传感器数据表 |
| Photores | 光敏传感器数据表 | Log | 端口数据日志表 |  

## 主要功能与实现  
* **传感器代码与实现**  
1.传感器无线组网的实现：[WSN_ZigBee](https://github.com/efishliu/Smart-Home-System/tree/master/WSN_ZigBee_Modification)  
2.各传感器具体功能实现：

| 代码 | 描述 | 代码 | 描述 |  
|:----: |:----: |:----: |:----:|  
| [Coordinator](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/Coordinator) | 协调器 | [TempAndHum](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/TempAndHum) | 温湿度传感器 |  
| [Touch](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/Touch) | 触摸传感器 | [PhotoRes](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/PhotoRes) | 光敏传感器 |  
| [PWM](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/PWM) | LED灯 | [Motor](https://github.com/efishliu/Smart-Home-System/tree/master/SerialApp/Motor) | 电机 |  

* **端口数据读取与处理**  
1.USB串口读取数据：[Coordinator.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/Coordinator.py)  
2.温湿度传感器数据转换：[TempAndHum.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/TempAndHum.py)；
光敏传感器数据转换：[PhotoResisitor.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/PhotoResisitor.py)；
触摸传感器的数据转换：[Touch.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/Touch.py)    
3.LED灯光控制：[PWM.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/PWM.py)；
电机控制[Motor.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/Motor.py)  

* **本地与云端数据库连接：**[mysqlcon.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/mysqlcon.py)  

* **数据可视化处理：**  
1.PC端可视化处理：[Display.py](https://github.com/efishliu/Smart-Home-System/blob/master/Smart-Home/Display.py)  
<div align=center>
<img src="https://github.com/efishliu/Smart-Home-System/blob/master/image/system.jpg?raw=true" width = 50% height = 50% />
</div>   
2.Web端可视化处理：[Web](https://github.com/efishliu/Smart-Home-System/tree/master/Web)  
<div align=center>
<img src="https://github.com/efishliu/Smart-Home-System/blob/master/image/system.jpg?raw=true" width = 50% height = 50% />
</div>  

  

