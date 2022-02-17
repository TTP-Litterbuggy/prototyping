#This script identifies a Blue obstacle and draws a bounding box around it.

#Dependencies
from cv2 import imshow
import numpy as np
import cv2



def findBlueObj(image):
    #Load image
    # image = cv2.imread(imagePath)
    original = image.copy()

    #Convert image into HSV and set range for yellow object
    # cv2.imshow('image',image)
    # hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    # lower_blue = np.array([92,214,59])
    # upper_blue = np.array([112,234,139])
    # lower_blue = np.array([95,255,104])
    # upper_blue = np.array([112,255,192])
    lower_blue = np.array([93,255,74]) #Hallway porter 1.6m
    upper_blue = np.array([115,255,154])
    # lower_blue = np.array([84,255,49]) #Hallway porter far 
    # upper_blue = np.array([125,230,163])

    #Generate a mask
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    #Find contours
    cnts = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = cnts[0] if len(cnts) == 2 else cnts[1]

    coord = []
    #Draw bounding box
    for c in cnts:
        x,y,w,h = cv2.boundingRect(c)
        
        # if (w*h < 50):continue #threshold small noises
        const = 0
        x -= const
        y -= const
        w += const
        h += const
        coord.append([(x,y),(x+w,y),(x,y+h),(x+w,y+h)])
        cv2.rectangle(original, (x, y), (x + w, y + h), (36,255,12), 2)

    for r in coord:
        cv2.circle(original, r[0], 5, (255, 0, 0), 2)
        cv2.circle(original, r[1], 5, (255, 0, 0), 2)
        cv2.circle(original, r[2], 5, (255, 0, 0), 2)
        cv2.circle(original, r[3], 5, (255, 0, 0), 2)
    #Show result
    cv2.imshow('mask', mask)
    cv2.imshow('original', original)
    cv2.waitKey()
    return coord
    

# if __name__ == '__main__':
#     testImagePath = './testImages/color_frame.jpg'
#     rect = findBlueObj(testImagePath)
#     # for r in rect:
        
        
