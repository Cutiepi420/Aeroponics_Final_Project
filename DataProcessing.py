#! /usr/bin/python
from time import strftime
import glob
import re
import string

#defines the current local time
#saves the data to a unique file based on the time collected
newtime = strftime("%Y-%m-%d")
with open('/Users/DRYalacki/Documents/Engineering/LightData/'+newtime+'-Compilation.txt','w+') as fo:
    for file in glob.glob(newtime+"*"):
        with open(file,'r') as fi:
            for row in fi:
                row = "".join([str(s) for s in row])
                line = string.replace(row,',','\t')
                tabs = line.count('\t')
                if tabs>2:
                    print(line)
                    fo.write(line+'\n')
