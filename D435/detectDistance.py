import imp
import cv2
# import pyrealsense2
from realsense_depth import *
from findBlueObstacle import findBlueObj
from getCenterCoord import getCenterCoord
from getImg import *

#To be finished

def getObstcaleDistance(img,depth_frame):
    visualize = False #Show result image 
    #Gets the coord of the blue obstacle bounding box
    coord = findBlueObj(img) #return the 4 corners for multiple bbox.
    centerCoord = getCenterCoord(coord)
    print('Center Coord: ',centerCoord)
    if visualize:
        cv2.circle(img,centerCoord,2,(0,0,255),2)
        cv2.imshow('img',img)
        cv2.waitKey()
    
    return depth_frame[centerCoord[0],centerCoord[1]]


#test
if __name__ == '__main__':
    dc = DepthCamera()
    depth_frame,color_frame = getD435Img(dc)
    getObstcaleDistance(color_frame,depth_frame)


