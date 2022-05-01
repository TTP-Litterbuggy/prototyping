# Program To Read video
# and Extract Frames
import cv2

# Function to extract frames
def FrameCapture(path):
    
    cap = cv2.VideoCapture('D:\\22Spring\\16-474\\Detection\\Examples\\output.avi')
    if cap.isOpened():
        print("HLELLO????")
        current_frame = 0
        while True:
            ret, frame = cap.read()
            if ret:
                name = f'frame{current_frame}.jpg'
                print(f"Creating file... {name}")
                if current_frame > 920 and current_frame < 922:
                    print('Saving?')
                    cv2.imwrite(name, frame)
            else:
                break
                
            current_frame += 1
        print(current_frame)
        cap.release()
    cv2.destroyAllWindows()

# Driver Code
if __name__ == '__main__':

    # Calling the function
    FrameCapture("D:\22Spring\16-474\Detection\Examples\output.avi")
