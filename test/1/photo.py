#coding=utf-8
from Tkinter import *
#导入tk模块
top = Tk()
#初始化Tk
top.title('定时更换图片')

# 获取屏幕的宽度和高度，并且在高度上考虑到底部的任务栏，为了是弹出的窗口在屏幕中间
screenwidth = top.winfo_screenwidth()
screenheight = top.winfo_screenheight() - 100
top.resizable(False, False)

bm1 = PhotoImage(file='C:\Users\92084\Desktop\1\1.gif')
bm2 = PhotoImage(file='C:\Users\92084\Desktop\1\2.gif')
bm3 = PhotoImage(file='C:\Users\92084\Desktop\1\3.gif')
bm4 = PhotoImage(file='C:\Users\92084\Desktop\1\4.gif')

label = Label(top, image=bm1)
label.bm = bm1
i = 1
def changeImage(i):
    if i % 3 == 1:
        label.configure(image = bm1)
        i = i + 1
        label.after(2000,changeImage,i)
    elif i % 3 == 2:
        label.configure(image=bm2)
        i = i + 1
        label.after(1000, changeImage,i)
    else:
        label.configure(image=bm3)
        i = i + 1
        label.after(6000, changeImage, i)
label.pack(fill=X,expand=1)
i = i + 1
label.after(2000,changeImage,i)
top.update_idletasks()
top.deiconify()    #now window size was calculated
top.withdraw()     #hide window again
top.geometry('%sx%s+%s+%s' % (top.winfo_width() + 10, top.winfo_height() + 10, (screenwidth - top.winfo_width())/2,
 (screenheight - top.winfo_height())/2) )    #center window on desktop

top.deiconify()
top.mainloop()