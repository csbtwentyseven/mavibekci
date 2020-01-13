
from firebase import firebase

firebase = firebase.FirebaseApplication('Database URL', None)
firebase.put('/python-example-f6d0b/Students/-LjLUhaWGuxNd5gOEmse','Name','Bob')
print('Record Updated')
