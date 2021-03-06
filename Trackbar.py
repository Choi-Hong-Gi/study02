import cv2 , numpy as np

win_name = 'Trackbar'

img= cv2.imread('./img/blank_500.jpg')

cv2.imshow(win_name,img)

def onChange(x):
    r = cv2.getTrackbarPos('R',win_name)
    g = cv2.getTrackbarPos('G',win_name)
    b = cv2.getTrackbarPos('B',win_name)
    print( x, r , g , b)
    img[ : ]= [ b , g , r]
    cv2.imshow(win_name, img) # 트랙바 생성
    
cv2.createTrackbar('R', win_name, 255, 255, onChange)
cv2.createTrackbar('G', win_name, 255, 255, onChange)
cv2.createTrackbar('B', win_name, 255, 255, onChange)

while True:
    if cv2.waitKey(0) & 0xFF == 27:
        break
    
cv2.destroyAllWindows()