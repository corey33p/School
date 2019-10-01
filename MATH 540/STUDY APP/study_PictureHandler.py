from PIL import Image, ImageTk
import os
from os import listdir
from os.path import isfile,join
import numpy as np
# from tkinter import filedialog
from random import randint

class PictureHandler:
    def __init__(self, parent):
        self.parent = parent
        self.mode = "question"
        self.questions_path = os.getcwd().replace('\\','/') + "/material/questions/"
        self.answers_path = os.getcwd().replace('\\','/') + "/material/answers/"
        self.current_image_index = 1
        self.default_image_path = os.getcwd().replace('\\','/') + "/source/default.jpg"
        self.get_questions()
        self.browse_images(init=True)
        self.last_function_used = 'random'
    def get_questions(self):
        self.questions_list = [f for f in listdir(self.questions_path) if isfile(self.questions_path + f)]
        self.questions_list = [self.questions_path + im for im in self.questions_list if "Thumbs.db" not in im]
        self.answers_list = [f for f in listdir(self.answers_path) if isfile(self.answers_path + f)]
        self.answers_list = [self.answers_path + im for im in self.answers_list if "Thumbs.db" not in im]
        if len(self.questions_list) != len(self.answers_list): 1/0
    def toggle_mode(self,manual=False): # display question vs display answer
        if manual: self.last_function_used = 'toggle'
        if self.mode == "question": 
            self.mode = "answer"
            self.current_folder = self.answers_path
            self.current_image_path = self.answer_filename
        elif self.mode == "answer": 
            self.mode = "question"
            self.current_folder = self.questions_path
            self.current_image_path = self.question_filename
        self.parent.display.update_image(self.current_image_path)
        if self.mode == "question": self.parent.display.scrolled_frame.canvas.yview_moveto(0)
    def browse_images(self,previous=False,init=False):
        if self.parent.display._hide_answer_check():
            if self.mode == "answer":
                self.toggle_mode(manual=False)
        if not init:
            if previous:
                self.last_function_used = 'previous'
                if self.current_image_index > 0: self.current_image_index -= 1
            else:
                self.last_function_used = 'next'
                number_of_results = max(len(self.questions_list),len(self.answers_list))
                if self.current_image_index < number_of_results: self.current_image_index += 1
        self.load_image_filenames(self.current_image_index)
        if self.mode == "question": self.current_image_path = self.question_filename
        elif self.mode == "answer": self.current_image_path = self.answer_filename
        self.parent.display.update_image(self.current_image_path)
        self.parent.display.update_probability_entry()
    def load_image_filenames(self,number):
        if self.parent.display._hide_answer_check():
            if self.mode == "answer":
                self.toggle_mode(manual=False)
        question_error = False
        answer_error = False
        if len(str(number))<0 or len(str(number))>3:
            question_error = answer_error = True
        else:
            name = ''
            for n in range(3-len(str(number))): name += '0'
            name += str(number) + '.PNG'
            self.question_filename = self.questions_path+"/"+name
            self.answer_filename = self.answers_path+"/"+name
            if not isfile(self.question_filename): question_error = True
            if not isfile(self.answer_filename): answer_error = True
        if question_error: self.question_filename = self.default_image_path
        if answer_error: self.answer_filename = self.default_image_path
    # def get_random_image(self):
        # self.last_function_used = 'random'
        # self.current_image_index = randint(0,max(len(self.questions_list),len(self.answers_list))-1)
        # self.load_image_filenames(self.current_image_index)
        # if self.mode == "question": self.current_image_path = self.question_filename
        # elif self.mode == "answer": self.current_image_path = self.answer_filename
        # self.parent.display.update_image(self.current_image_path)
    def go_to_image(self,number):
        if self.parent.display._hide_answer_check():
            if self.mode == "answer":
                self.toggle_mode(manual=False)
        try: number = int(number)
        except: return
        if number not in range(1,len(self.questions_list)+1): return
        self.current_image_index = number
        self.load_image_filenames(self.current_image_index)
        if self.mode == "question": self.current_image_path = self.question_filename
        elif self.mode == "answer": self.current_image_path = self.answer_filename
        self.parent.display.update_image(self.current_image_path)
        self.parent.display.update_probability_entry()
    def repeat_function(self,event):
        if str(self.parent.display.primary_window.focus_get()) != ".": # checks if focus is on image number entry. if so, enter button is utilized to go to said image number
            self.parent.display.primary_window.focus()
            return
        if self.last_function_used == 'toggle': self.toggle_mode()
        elif self.last_function_used =='previous': self.browse_images(previous = True)
        elif self.last_function_used == 'next': self.browse_images()
        elif self.last_function_used == 'random': self.parent.hat.select()
        self.parent.display.update_probability_entry()