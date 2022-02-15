import cv2

global mouseX,mouseY
img = cv2.imread("./testImages/color_frame.jpg")
cv2.imshow('image',img)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
print(hsv[355,270])
cv2.imshow('hsv',hsv)
cv2.waitKey()

#[ 11  13 161]

# mask = cv2.inRange(hsv,(110,50,50), (130,255,255) )
# cv2.imshow("blue", mask);cv2.waitKey();cv2.destroyAllWindows()