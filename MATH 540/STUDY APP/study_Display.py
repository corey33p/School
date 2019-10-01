from PIL import Image, ImageTk
import tkinter as tk
from tkinter import Canvas,Tk,ttk,Label,Entry,Button,mainloop,Text,Frame,IntVar,Checkbutton
import os
import numpy as np
from tkinter import filedialog
from Vertical_Scroll import *

class Display:
    def __init__(self, parent):
        self.parent = parent
        self.main_font = ("Courier", 22, "bold")
        self.max_win_size = (1278,950)
        self.image_size = ((self.max_win_size[0]-5,self.max_win_size[1]-230))
        self.im_dim_size = min(self.max_win_size)
        self.result_index = 0
        self.setup_window()
    def open_images(self):
        pil_img = Image.open('source/random.gif').resize((80,80), Image.ANTIALIAS)
        self.random_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/left_arrow.gif').resize((80,80), Image.ANTIALIAS)
        self.left_arrow_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/right_arrow.gif').resize((80,80), Image.ANTIALIAS)
        self.right_arrow_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/toggle.gif').resize((80,80), Image.ANTIALIAS)
        self.toggle_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/close.gif').resize((80,80), Image.ANTIALIAS)
        self.close_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/accept.gif').resize((80,80), Image.ANTIALIAS)
        self.accept_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/good.gif').resize((80,80), Image.ANTIALIAS)
        self.good_photo=ImageTk.PhotoImage(pil_img)
        pil_img = Image.open('source/bad.gif').resize((80,80), Image.ANTIALIAS)
        self.bad_photo=ImageTk.PhotoImage(pil_img)
    def setup_window(self):
        # initial setup
        self.primary_window = Tk()
        self.open_images()
        self.primary_window.wm_title("Physics Flashcards")
        self.primary_window.geometry('1274x960-1+0')
        self.primary_window.minsize(width=100, height=30)
        self.primary_window.maxsize(width=self.max_win_size[0], height=self.max_win_size[1])
        
        # image & canvas
        self.im = Image.open("source/default.jpg")
        im_size = self.im.size
        tk_im_size = self.get_size(self.image_size,self.im.size)
        _im = self.im.resize(tk_im_size,Image.ANTIALIAS)
        self.tk_im = ImageTk.PhotoImage(_im)
        
        self.im_frame = ttk.Frame(self.primary_window)
        self.im_frame.grid(row=0,column=0,columnspan=2,sticky="nsew")
        self.im_frame.columnconfigure(0, weight=1)
        self.im_frame.rowconfigure(0, weight=1)
        self.primary_window.columnconfigure(0, weight=1)
        self.primary_window.rowconfigure(0, weight=1)
        
        self.scrolled_frame = VerticalScrollGrid(self.im_frame)
        self.scrolled_frame.grid(row=0,column=0, sticky="nsew")
        
        self.canvas_frame = ttk.Frame(self.scrolled_frame.frame)
        self.canvas_frame.grid(row=0, column=0, sticky="nsew")
        self.canvas_frame.columnconfigure(0, weight=1)
        
        self.im_canvas = Canvas(self.canvas_frame,width=self.image_size[0],height=self.image_size[1])
        self.im_canvas_image = self.im_canvas.create_image((0,0), anchor='nw',image=self.tk_im)
        self.im_canvas.grid(row=0, column=0,columnspan=2, sticky="ew")
        
        # bottom entry
        self.bottom_info_frame = ttk.Frame(self.primary_window)
        self.bottom_info_frame.grid(row=3, column=0)
        #
        Label(self.bottom_info_frame, text="Problem Number:",font=self.main_font).grid(row=0, column=0)
        self.found_result_entry = Entry(self.bottom_info_frame,justify='right')
        self.found_result_entry.config(font=self.main_font,width=3,state='disabled')
        self.found_result_entry.grid(row=0, column=1)
        #
        Label(self.bottom_info_frame, text=" Problem Probability:",font=self.main_font).grid(row=0, column=2)
        self.probability_entry = Entry(self.bottom_info_frame,justify='right')
        self.probability_entry.config(font=self.main_font,width=9,state='disabled')
        self.probability_entry.grid(row=0, column=3)
        #
        self.hide_answer_check = IntVar()
        self.hide_answer_check.set(1)
        self.hide_answers_button = Checkbutton(self.bottom_info_frame, text="Auto Hide Answer", variable=self.hide_answer_check,font=self.main_font)
        self.hide_answers_button.grid(row=0,column=4)
        
        # bottom buttons
        self.bottom_buttons_frame = ttk.Frame(self.primary_window)
        self.bottom_buttons_frame.grid(row=4,column=0,columnspan=2)
        #
        self.random_button = Button(self.bottom_buttons_frame,
                                    command= self.parent.hat.select,
                                    image=self.random_photo,
                                    width="80",height="80")
        self.random_button.grid(row=0,column=0)
        #
        self.previous_button = Button(self.bottom_buttons_frame,
                                      command=lambda: self.browse_images(previous=True),
                                      image=self.left_arrow_photo,
                                      width="80",height="80")
        self.previous_button.grid(row=0,column=1)
        #
        self.next_button = Button(self.bottom_buttons_frame,
                                  command=self.browse_images,
                                  image=self.right_arrow_photo,
                                  width="80",height="80")
        self.next_button.grid(row=0,column=2)
        #
        self.toggle_button = Button(self.bottom_buttons_frame,
                                    command=self.parent.picture_object.toggle_mode,
                                    image=self.toggle_photo,
                                    width="80",height="80")
        self.toggle_button.grid(row=0,column=3)
        #
        self.good_button = Button(self.bottom_buttons_frame,
                                   command=self.parent.hat.reduce_probability,
                                   image=self.good_photo,
                                   width="80",height="80")
        self.good_button.grid(row=0,column=4)
        #
        self.bad_button = Button(self.bottom_buttons_frame,
                                   command=self.parent.hat.increase_probability,
                                   image=self.bad_photo,
                                   width="80",height="80")
        self.bad_button.grid(row=0,column=5)
        #
        Label(self.bottom_buttons_frame, text="Go To Problem #:",font=self.main_font).grid(row=0, column=6)
        self.go_to_problem_entry = Entry(self.bottom_buttons_frame,justify='right')
        self.go_to_problem_entry.config(font=self.main_font,width=3)
        self.go_to_problem_entry.grid(row=0,column=7)
        self.go_to_problem_button = Button(self.bottom_buttons_frame,
                                    command=lambda: self.parent.picture_object.go_to_image(self.go_to_problem_entry.get()),
                                    image=self.accept_photo,
                                    width="80",height="80")
        self.go_to_problem_button.grid(row=0,column=8)
        self.go_to_problem_entry.bind("<Return>", lambda event: self.parent.picture_object.go_to_image(self.go_to_problem_entry.get()))
        #
        self.close_button = Button(self.bottom_buttons_frame,
                                   command=self.parent.close,
                                   image=self.close_photo,
                                   width="80",height="80")
        self.close_button.grid(row=0,column=9)
        #
        
        self.primary_window.bind("<Down>", lambda event: self.browse_images())
        self.primary_window.bind("<Up>", lambda event: self.browse_images(previous=True))
        
        self.update_image(self.parent.picture_object.current_image_path)
        self.primary_window.bind('<Return>', self.parent.picture_object.repeat_function)
    def browse_images(self,previous=False):
        self.scrolled_frame.go_to_top()
        self.parent.picture_object.browse_images(previous=previous)
    def _hide_answer_check(self): return int(self.hide_answer_check.get())
    def update_image(self, im_path):
        im = Image.open(im_path)
        new_size = self.get_size((self.image_size[0],10000),im.size)
        im = im.resize(new_size,Image.ANTIALIAS)
        self.tk_im = ImageTk.PhotoImage(im)
        self.im_canvas.config(width=new_size[0],height=new_size[1])
        self.im_canvas.itemconfig(self.im_canvas_image, image=self.tk_im)
        self.update_result_entry(im_path)
        if new_size[1] <= self.image_size[1]:
            self.scrolled_frame.canvas.configure(state="disabled")
        else:
            self.scrolled_frame.canvas.configure(state="normal")
    def update_result_entry(self,text):
        text=text[text.rfind("/")+1:]
        text=text[:text.rfind(".")]
        self.found_result_entry.config(state="normal")
        self.found_result_entry.delete(0,'end')
        self.found_result_entry.insert('end',text)
        self.found_result_entry.xview_moveto(1.0)
        self.found_result_entry.config(state="disabled")
    def update_probability_entry(self):
        index = self.parent.picture_object.current_image_index
        p = self.parent.hat.probabilities[index]
        text = str(p)
        self.probability_entry.config(state="normal",width=len(text))
        self.probability_entry.delete(0,'end')
        self.probability_entry.insert('end',text)
        self.probability_entry.xview_moveto(1.0)
        self.probability_entry.config(state="disabled")
    def get_size(self, max_size, input_size, circumscribe = False):
        # fits dimensions to a target size while maintaining aspect ratio
        if (input_size[0] != max_size[0]) or (input_size[1] != max_size[1]):
            if not circumscribe:
                if (input_size[0] > max_size[0]) or (input_size[1] > max_size[1]):
                    if input_size[0]/input_size[1] > max_size[0]/max_size[1]:
                        resized_size=(int(max_size[0]),int(max_size[0]*input_size[1]/input_size[0]))
                    else:
                        resized_size=(int(max_size[1]*input_size[0]/input_size[1]),int(max_size[1]))
                else:
                    if input_size[0]/input_size[1] < max_size[0]/max_size[1]:
                        resized_size=(int(max_size[1]*input_size[0]/input_size[1]),int(max_size[1]))
                    else:
                        resized_size=(int(max_size[0]),int(max_size[0]*input_size[1]/input_size[0]))
            else:
                if (input_size[0] > max_size[0]) or (input_size[1] > max_size[1]):
                    if not (input_size[0]/input_size[1] > max_size[0]/max_size[1]):
                        resized_size=(int(max_size[0]),int(max_size[0]*input_size[1]/input_size[0]))
                    else:
                        resized_size=(int(max_size[1]*input_size[0]/input_size[1]),int(max_size[1]))
                else:
                    if not (input_size[0]/input_size[1] < max_size[0]/max_size[1]):
                        resized_size=(int(max_size[1]*input_size[0]/input_size[1]),int(max_size[1]))
                    else:
                        resized_size=(int(max_size[0]),int(max_size[0]*input_size[1]/input_size[0]))
        else: resized_size = input_size
        return resized_size