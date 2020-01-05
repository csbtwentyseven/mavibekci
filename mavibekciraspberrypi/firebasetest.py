from firebase import firebase
import serial
import time

arduino=serial.Serial('/dev/ttyUSB0', 9600)


firebase = firebase.FirebaseApplication('https://tubitak2020-8e6a2.firebaseio.com/', None)
    
while True:
    result = firebase.get('/hareket', '')
    if(result == "far"):
        arduino.write(b'a')
    else:
        arduino.write(b'd')
