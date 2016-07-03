# -*- coding: utf-8 -*-
import os
import os.path

def getList(path):
    allFile = []
    for root, dirs, files in os.walk(path):
        for name in files:
            allFile.append(root + '\\' + name)
    return allFile

def getPome(fileName):
    pome = 0
    if selFile(fileName):
        try:
            file = open(fileName,'r',encoding="utf8")
            for line in file:
                pome += 1
        except:
            file = open(fileName,'r',encoding="gbk")
            for line in file:
                pome += 1
        print(fileName, '\n', pome)
    return pome

def selFile(fileName):
    try:
        (name, ext) = fileName.split(".")
        if ext == 'c' or ext == 'cpp' or ext == 'py' or ext == 'h':
            return True
        else:
            return False
    except:
        return False

pome = 0      
directory = input("请输入文件夹目录\n>>>")
allFile = getList(directory)
for fileName in allFile:
    pome += getPome(fileName)
print("目录下共有   ",pome,"   行代码")
