import sqlite3
from tkinter import *

def on_closing (event=None):
    root.quit()


root = Tk()
root.title("Exam Form")

L1 = Label(root, text = "PRN: ")
E1 = Entry(root, bd = 5)

root.protocol("WM_DELETE_root", on_closing)
root.mainloop()
