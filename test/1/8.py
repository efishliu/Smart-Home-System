#coding=utf8
import matplotlib.pyplot as plt  

x3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
y3=[30,31,31,32,33,35,35,40,47,62]  
  

group_labels = ['64k', '128k','256k','512k','1024k','2048k','4096k','8M','16M','32M','64M','128M','256M','512M']  
plt.title('temp go')  
plt.xlabel('time')  
plt.ylabel('temp')  
  
#plt.plot(x1, y1,'r', label='broadcast')  
#plt.plot(x2, y2,'b',label='join')  
#plt.xticks(x1, group_labels, rotation=0)  
plt.xticks(x3, group_labels, rotation=0)    
plt.plot(x3, y3,'r', label='temp')  
plt.legend(bbox_to_anchor=[0.3, 1]) 
plt.grid() 
 
plt.show()