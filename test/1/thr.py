#coding=utf8
import Tkinter 
import thread
import time
def win():
    root=Tkinter.Tk()
    root.title('Display windows')
    temp_lable1=Tkinter.Label(root,text='温度',font=("Arial", 12))
    temp_lable2=Tkinter.Label(root,text='20.5',fg='red')
    temp_lable1.pack(side='left')
    temp_lable2.pack(side='right')
    hum_lable1=Tkinter.Label(root,text='湿度',font=("Arial", 12))
    hum_lable2=Tkinter.Label(root,text='43.6',)
    hum_lable1.pack(side='left')
    hum_lable2.pack(side='right')
    root.mainloop()


def deal():
    a=input('input a:\n')
    b=input('input b:\n')
    print a+b

if __name__ == '__main__':
    thread.start_new_thread(deal,())
    thread.start_new_thread(win,())
    time.sleep(30000)