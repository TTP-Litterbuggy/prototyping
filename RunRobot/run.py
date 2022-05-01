import serial
import time
import numpy as np
import cv2
from realsense_depth import *
import torch
import time
from controller import *


arduino = serial.Serial('/dev/ttyACM0',115200,timeout=5)

 
input_str = arduino.readline()
#print("Read input : " + input_str.decode("utf-8").strip() + "from mega")

def write2Arduiono(x):
    arduino.write(bytes(x,'utf-8'))
    time.sleep(0.05)
    data = arduino.readline().decode('utf-8').rstrip()
    return data

def checkTurn(cx):
    if abs(cx - 320) < 30:
        return False
    else:
        return True

def checkDrive(dist):
    if dist < 100:
        return False
    else:
        return True
### INIT ###
print('Initializing model ... \n')
model = torch.hub.load(repo_or_dir = '/home/pi/TTP/yolov5',source = 'local', model = 'custom',path = '/home/pi/TTP/yolov5/best_hw.pt',)
print('Initializing camera ... \n')
dc = DepthCamera()
time.sleep(3)
print('Finished initialization !')
print('Time start!!!')
t0 = time.time()
t_prev = 0
t = 0

driveFlag = True
turnFlag = True
### END INIT ###


while 1:
    t1 = time.time()
    t = t1 - t0
    
    if (t > 120): break
    if (t > t_prev + 5):

        t_prev = t
        print('time : %f\n' ,t)
        _,depth_frame, frame = dc.get_frame()
        frame = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
        results = model(frame)
        result_matrix = results.xyxy[0]

        #If something is detected just go idk
        if result_matrix.nelement() != 0:
            print(results.pandas().xyxy[0]) #Print sthe things the model detected
            result_matrix = result_matrix.numpy()
            xmin,ymin,xmax,ymax,_,_ = result_matrix[0,:] #Get the one with highest conf
            c1,c2 = (int(xmin),int(ymin)),(int(xmax),int(ymax))
            center_point = round((c1[0]+c2[0])/2),round((c1[1]+c2[1])/2)
            cx = center_point[0]
            cy = center_point[1]
            dist = depth_frame[center_point[1], center_point[0]]
            print('cx : ', cx)
            print('dist : ',dist)
            data = write2Arduiono(str(100))
            print(data)
            #Now pass to the controller
            ##UNCOMMENT FOR ACTUAL
            # turn_time,drive_time = controller(cx,dist)
            # #Send the controller output to arduino
            # turnFlag = checkTurn(cx)
            # if (turnFlag):
            #     data = write2Arduiono(str(turn_time))
            #     print('turning for : %s ms'%(data))
            #     turnFlag = False
            # driveFlag = checkDrive(dist)
            # if (driveFlag):
            #     data = write2Arduiono(str(drive_time))
            #     print('driving for : %s ms'%(data))
            #     driveFlag = False
            ###UNCOMMENT END

            time.sleep(2)

        else:
            print('Did not detect anything :( \n')
    
    else:
        continue
        # time.sleep(3)
    
    
    

