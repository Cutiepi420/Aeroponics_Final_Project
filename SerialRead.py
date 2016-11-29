#! /usr/bin/python
import serial
import time
from time import gmtime, strftime
import glob
import csv


# serial allows us to read from the serial monitor
ser = serial.Serial('/dev/ttyACM0',9600)

#vals holds data for IR, Full Spectrum, Visible Light and Lux outputs
vals = ser.readline().split("\t")
#print 'val',vals
length = len(vals)
#print 'Length: ',length
#this is creating an array with the data values
x = [int(s) for s in vals if s.isdigit()]
#print 'X is',x

#if the data is bad, we will take it again.
if length!=5:
    #print "this data sucks\n"
    vals = ser.readline().split("\t")
    #print vals
    length = len(vals)
    #print 'Length: ',length
    x = [int(s) for s in vals if s.isdigit()]
print 'X is',x

if length!=5:
    #print "this data sucks again\n"
    vals = ser.readline().split("\t")
    #print vals
    length = len(vals)
    #print 'Length: ',length
    x = [int(s) for s in vals if s.isdigit()]
print 'X is',x


newtime = strftime("%Y-%m-%d-%M")
with open('/home/pi/Aeroponics/LightData/'+newtime+'.csv','w+') as fo:
    fo.write(",".join(str(y) for y in x))
ser.close()
