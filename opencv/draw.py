## 0806  learning somthing about image editting !!!!

import numpy as np
import cv2
#create a black image
img = np.zeros((512, 512, 3), np.uint8)
#draw a diagnal blue line with thickness of 5px
# in opencv color is (B,G,R) ==> so following is blue line
# args(img(numpy array), start pos, end pos, color, thickness ) ==> test : can the two pos inverted?
cv2.line(img, (0,0), (511,511), (255,0, 0), 5)

# draw rectangle
#args (img, top-left pos, bottom-right pos, color(green), thickness)
cv2.rectangle(img, (384, 0), (510, 128), (0,255,0), 3)

# draw circle
#args (img, center pos, radius, color(red), thickness(-1 means that a filled circle is to be drawn)) 
cv2.circle(img, (447, 63), 63, (0,0,255), -1)

# draw ellipse (angle are in 0~360)
#args (img, center pos, (major axis len, minor axis len), rotation angle, visual start_angle, visual end_angle, ellipse color(a scalar => different from the above), thick)
cv2.ellipse(img, (256,256), (100, 50), 40, 0, 200, 255, -1)

#add text to images
#args (img, str text, text pos(bottom left pos),font type, font size, color, thick, line type (cv2.LINE_AA recommend))
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img, 'OpenCV', (10,400), font, 4, (255,255,255), 2)

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
