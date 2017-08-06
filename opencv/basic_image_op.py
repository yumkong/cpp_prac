# access pixel values and modify them
import cv2
import numpy as np

img = cv2.imread('bird.jpg')

# can access a pixel value by (row, col), for opencv(BGR) image, returns 1x3 array of B, G, R values. 
# for grayscale image, return intensity
## NOTE numpy is optimized for fast array calculation, simply accessing each and every pixel values is slow
px = img[10, 10]
blue = img[10,10,0] # a scalar of numpy.uint8

# array.item can be better used to access individual pixel
# visiting
img.item(10,10,2)
# changing
img.itemset((10,10,2), 100)

# image proterties
print img.shape #[row, col, chl]
print img.size  # total number of pixels
print img.dtype # pixel datatype=> very important, many errors in opencv-python code is by invalid datatype

# roi using numpy indexing
part = img[40: 50, 20:80]
img[130:140, 100:160] = part

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#split BGR image into single channels
b,g,r = cv2.split(img)
# merge individual channels
img = cv2.merge((b,g,r))
