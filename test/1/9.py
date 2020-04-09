#coding=utf8
import matplotlib, sys
matplotlib.use('TkAgg')
from numpy import arange, sin, pi
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
from Tkinter import *

root=Tk()
root.title('windows')
#root.geometry("400x300")

Label(root, text='物联网感知课程设计',font=('宋体', 20)).pack()
#温度模块展示
fm1=Frame(root)
templabel_name=Label(fm1,text='温度',font=('宋体', 15))
templabel_name.pack(side=LEFT,pady=10)
templabel_val=Label(fm1,text='20',font=('宋体', 15))
templabel_val.pack(side=LEFT,padx=30)
fm1.pack(side=LEFT,pady=10)   

#-------------------------------------------------------------------------------

f = Figure(figsize=(5,4), dpi=100)
a = f.add_subplot(111)
t = [1.5,2.3,3,4,5]
s = [1.4,1.6,1.4,1.9,5.6]
a.plot(t,s)

a.legend(bbox_to_anchor=[0.3, 1])
a.grid() 

dataPlot = FigureCanvasTkAgg(f, master=root)
dataPlot.show()
dataPlot.get_tk_widget().pack(side=TOP)

#-------------------------------------------------------------------------------
root.mainloop()