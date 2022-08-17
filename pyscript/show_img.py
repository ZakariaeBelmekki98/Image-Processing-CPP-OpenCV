import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import sys

if(len(sys.argv) < 3):
    print("show_img.py: Takes 2 arguments: [filename] [type:RGB/GRAY]")
    exit()

# parse arguments
filename = str(sys.argv[1])
img_type = str(sys.argv[2])

channels = 0;
if(img_type=='RGB'):
    channels=3
else:
    channels=1

# read the img dat file into a three dimensional tensor

file = pd.read_csv(filename, sep=' ', header=None)
print(file)

img_pixels = np.zeros((32, 32, channels), dtype=np.uint8)

for i in range(32):
    for j in range(32):
        for k in range(channels):
            img_pixels[i][j][k] = file.iloc[i,j*channels+k];

plt.imshow(img_pixels, interpolation='nearest')
plt.show()
