from study_Display import Display
from study_PictureHandler import PictureHandler
from study_Probabilities import Hat
from tkinter import mainloop
import os
import win32gui
import win32con

class Parent:
    def __init__(self):
        class Nothing:
            def update_image(self,im_path): return
            def _hide_answer_check(self): return
            def update_probability_entry(self): return
        self.display = Nothing()
        self.picture_object = PictureHandler(self)
        self.hat = Hat(self)
        self.display  = Display(self)
        self.resize_CLI_window()
        self.hat.select()
        mainloop()
    def resize_CLI_window(self):
        def get_windows():
            def check(hwnd, param):
                title = win32gui.GetWindowText(hwnd)
                if 'study_Main' in title and 'Notepad++' not in title:
                    param.append(hwnd)
            wind = []
            win32gui.EnumWindows(check, wind)
            return wind
        self.cli_handles = get_windows()
        for window in self.cli_handles:
            win32gui.MoveWindow(window,0,0,1300,1000,True)
    def close(self):
        for handle in self.cli_handles:
            win32gui.PostMessage(handle,win32con.WM_CLOSE,0,0)

if __name__ == '__main__':
    main_object = Parent()
    