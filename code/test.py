import os
import glob

files = glob.glob('*')
for file in files:
    path = './' + file + '/*'
    ff = glob.glob(path)
    if len(ff) == 0:
        print(file)