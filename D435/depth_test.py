import pyrealsense2 as rs
import numpy as np
from realsense_depth import *
import cv2
from getImg import getDepthImg
import time

#Trying to detect the obstacle on a flat floor.


dc = DepthCamera()
time.sleep(3)
print('Camera is on\n')
print('Getting Depth Image ...\n')
depth_img = getDepthImg(dc)

avg_depth = np.average(depth_img)


# while True:
#     _, depth_frame, _ = dc.get_frame()
#     print(depth_frame.shape)
#     # avg_depth = 
#     # depth_frame = (depth_frame/256).astype(np.uint8)
#     # depth_frame *= 10
#     # depth_frame = cv2.applyColorMap(depth_frame,cv2.COLORMAP_JET)

#     # Show distance for a specific point
#     # cv2.circle(color_frame, point, 4, (0, 0, 255))
    

#     # cv2.putText(color_frame, "{}mm".format(distance), (point[0], point[1] - 20), cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 0), 2)

#     # cv2.imshow("depth frame", depth_frame)
#     # cv2.imshow("Color frame", color_frame)
#     key = cv2.waitKey(1)
#     if key == 27:
#         break