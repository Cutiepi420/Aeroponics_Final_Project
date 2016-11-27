#! /usr/bin/python
from time import gmtime,strftime
import time
import sys
import os
import glob

#The code below will obtain a time stamp, and will search through all of the files in the folder
#containing light data and append them to a single text file with the compiled data.
#Also, if the length of the row is not greater than 4, this means that there was an error in
#capturing the data.

newtime = strftime("%Y-%m-%d")
with open('/home/pi/Aeroponics/LightData/'+newtime+'-Compilation.csv','w+') as fo:
    for file in glob.glob(newtime+"*"):
        with open(file,'r') as fi:
            for row in fi:
                print row
                if not len(row)>4:
                    print("".join(row))
                    fo.write(fi.read())
                fo.write(fi.read())
