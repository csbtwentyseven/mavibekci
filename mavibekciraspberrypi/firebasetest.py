#Cezeri Robotics 2020 Tubitak
#Mavi Bekçi

from firebase import firebase
import serial

#gerekli kütüphaneleri içeri aktarıyoruz.

firebase = firebase.FirebaseApplication('https://tubitak2020-8e6a2.firebaseio.com/', None) # veritabanı bağlantımızı yapıyoruz.
arduino=serial.Serial('/dev/ttyUSB0', 9600) # arduino seri monitorüne bağlanıyoruz.
def kontrol():
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

def sensorVeri():
    firebase = firebase.FirebaseApplication('https://tubitak2020-8e6a2.firebaseio.com/', None)

    if(ser.readline() == 26): #arduinomuzu su temizse 26 şifresini gönderecek şekilde programladık.böylece arduinonun bağlı olduğu sensör suyu temiz algılarsa gerçek zamanlı olarak veritabanına oradan da android uygulamasına aktarılacak.
        firebase.put('/tubitak2020-8e6a2','/message','Su Temiz.')
        print('Record Updated')

    elif(ser.readline() == 13):#arduinomuzu su kirliyse 13 şifresini gönderecek şekilde programladık.böylece arduinonun bağlı olduğu sensör suyu kirli algılarsa gerçek zamanlı olarak veritabanına oradan da android uygulamasına aktarılacak.
        firebase.put('/tubitak2020-8e6a2','/message','Su Kirli.')
        print('Record Updated')

    else:
        pass
    
while True:
    kontrol()
    sensorVeri()


