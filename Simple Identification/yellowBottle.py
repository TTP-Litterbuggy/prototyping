#This script identifies a yellow bottle and draws a bounding box around it.

#Dependencies
import numpy as np
import cv2



def findYellowObj(imagePath):
    #Load image
    image = cv2.imread(imagePath)
    original = image.copy()

    #Convert image into HSV and set range for yellow object
    image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower = np.array([22, 93, 0])
    upper = np.array([45, 255, 255])

    #Generate a mask
    mask = cv2.inRange(image, lower, upper)

    #Find contours
    cnts = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = cnts[0] if len(cnts) == 2 else cnts[1]

    #Draw bounding box
    for c in cnts:
        x,y,w,h = cv2.boundingRect(c)
        cv2.rectangle(original, (x, y), (x + w, y + h), (36,255,12), 2)

    #Show result
    cv2.imshow('mask', mask)
    cv2.imshow('original', original)
    cv2.waitKey()


if __name__ == '__main__':
    testImagePath = './testImages/yellow1.jpg'
    findYellowObj(testImagePath)
