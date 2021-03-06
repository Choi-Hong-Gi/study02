import cv2

cap = cv2.VideoCapture(0)

while cap.isOpened(): 
    ret, img = cap.read() 
    if ret:
        cv2.imshow('camera-0', img)
        if cv2.waitKey(1) & 0xFF == 27: #esc code, end
            break
    else:
        print('no camera!')
        break
    
cap.release()
cv2.destroyAllWindows()