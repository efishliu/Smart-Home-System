#coding=utf8
import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg 
from matplotlib.figure import Figure
from Tkinter import *


root = Tk()

f = Figure(figsize=(5,4),dpi=100)
f_plot = f.add_subplot(111 )

def other_picture_alg():   #数据相关的算法应该与plot分离开
    x=[1,2,3,4,5,6,7,8,9,10]      
    y=[3,6,9,12,15,18,15,12,15,18]
    return x,y


def draw_picture():
    f_plot.clear()
    x=[1,2,3,4,5,6,7,8,9,10]      #关于数据的部分可以提取出来
    y=[3,6,9,12,15,18,21,24,27,30]
    f_plot.plot(x,y)
    canvs.draw()

def draw_picture2():
    f_plot.clear()
    x=[1,2,3,4,5,6,7,8,9,10]     #关于数据的部分可以提取出来
    y=[2,4,6,8,10,8,6,4,2,0]
    f_plot.plot(x,y)
    canvs.draw()

def draw_picture3():
    f_plot.clear()
    x,y = other_picture_alg()    #使用由算法生成的数据，可以避免重复的运算过程
    f_plot.plot(x,y)
    canvs.draw()

canvs = FigureCanvasTkAgg(f,root)
canvs.get_tk_widget().pack(side=TOP)
Button(root, text = 'pic',command = draw_picture).pack()
Button(root, text = 'pic2',command = draw_picture2).pack()
Button(root, text = 'pic3',command = draw_picture3).pack()

root.mainloop()