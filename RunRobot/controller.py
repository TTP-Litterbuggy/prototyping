def controller(cx,dist):
    turnGain = 1
    driveGain = 1
    center = 320
    err = (cx-center)/320
    turn_time = round(err * turnGain) #Pos = turn right, Neg = turn left
    drive_time = round(dist * driveGain) 
    print('turn time : ', turn_time)
    print('drive time : ', drive_time)
    return turn_time,drive_time