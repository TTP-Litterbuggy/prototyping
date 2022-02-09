import cv2
import pyrealsense2
from realsense_depth import *

point = (400, 300)

def show_distance(event, x, y, args, params):
    global point
    point = (x, y)

# Initialize Camera Intel Realsense
dc = DepthCamera()

# Create mouse event
cv2.namedWindow("Color frame")
cv2.setMouseCallback("Color frame", show_distance)

while True:
    ret, depth_frame, color_frame = dc.get_frame()
    # print(type(depth_frame))
    # print(np.shape(depth_frame))
    # depth_frame = cv2.cvtColor(depth_frame, cv2.COLOR_BGR2GRAY)
    # depth_frame = np.reshape(depth_frame,(480,640,1))
    distance = depth_frame[point[1], point[0]]
    depth_frame = (depth_frame/256).astype(np.uint8)
    depth_frame *= 10
    depth_frame = cv2.applyColorMap(depth_frame,cv2.COLORMAP_JET)

    # Show distance for a specific point
    cv2.circle(color_frame, point, 4, (0, 0, 255))
    

    cv2.putText(color_frame, "{}mm".format(distance), (point[0], point[1] - 20), cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 0), 2)

    cv2.imshow("depth frame", depth_frame)
    cv2.imshow("Color frame", color_frame)
    key = cv2.waitKey(1)
    if key == 27:
        break