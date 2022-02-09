import cv2
import pyrealsense2
from realsense_depth import *

def getImg(dc,point,depth = False):
    ret, depth_frame, color_frame = dc.get_frame()
    distance = depth_frame[point[1], point[0]]
    depth_frame = (depth_frame/256).astype(np.uint8)
    depth_frame *= 10
    depth_frame = cv2.applyColorMap(depth_frame,cv2.COLORMAP_JET)

    cv2.imshow("Color frame", color_frame)
    cv2.waitKey(0)
    print(color_frame)
    print(np.max(color_frame))
    cv2.imwrite('color_frame.jpg',color_frame)
    if depth:
        cv2.imwrite('depth_frame.jpg',depth_frame)

    return 0


if __name__ == '__main__':
    dc = DepthCamera()
    point = (400, 300)
    getImg(dc,point)
