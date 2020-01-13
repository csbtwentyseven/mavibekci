#Cezeri Robotics 2020 Tubitak
#Mavi Bekçi

from firebase import firebase
import serial
import time
#gerekli kütüphaneleri içeri aktarıyoruz.



arduino=serial.Serial('/dev/ttyUSB0', 9600) # arduino seri monitorüne bağlanıyoruz.


firebase = firebase.FirebaseApplication('https://tubitak2020-8e6a2.firebaseio.com/', None) # veritabanı bağlantımızı yapıyoruz.
    
while True:
    sonuc  = firebase.get('/hareket', '') # veritabanından /hareket yolu altındaki verimizi çekiyoruz.(Mobil uygulamadaki butonların kontrol ettiği veri.)
    if(sonuc == "d"):
        arduino.write(b'd') #veri arduino seri ekranına karakterin ASCII karşılığını gönderecek.

    elif(sonuc == "far"):
        arduino.write(b'f') #sonuçlar anahtar kelimelerle eşleşirse bilgiyi arduino seri monitörüne gönderiyoruz.Python kısmı burada sona eriyor.

    elif(sonuc == "i"):
        arduino.write(b'i')

    elif(sonuc == "sag"):
        arduino.write(b'g')

    elif(sonuc == "sol"):
        arduino.write(b'l')

    elif(sonuc == "o"):
        arduino.write(b'o')


