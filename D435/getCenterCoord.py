def getCenterCoord(coord):
    #coord = [[(x1,y2),(x2,y2),(x3,y3),(x4,y4)], [...],[...]]
    maxArea = 0
    maxAreaCoord = None
    for r in coord:
        (x1,y1) = r[0] #top left
        (x2,y2) = r[1] #top right
        (x3,y3) = r[2] #bot left
        (x4,y4) = r[3] #bot right

        area = (x3-x1)*(y4-y2)
        if area > maxArea:
            maxAreaCoord = r
    (x1,y1) = r[0] #top left
    (x2,y2) = r[1] #top right
    (x3,y3) = r[2] #bot left
    (x4,y4) = r[3] #bot right
    center = ((x1+x2)//2,(y1+y3)//2)
    return center


