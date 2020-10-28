##########################
# Author : Bassirou NGOM
# modification: Moussa DIALLO 
# date : 04/01/2019
# licence: MIT
##########################


from serial import Serial
from datetime import datetime
import urllib2, urllib
serial_port = Serial(port='/dev/cu.wchusbserial1410', baudrate=9600)
while True:
    message = serial_port.readline()
    message = message[:5]

    for lettre in message:
        if lettre in "1234567890.": # lettre est une chiffre ou point
            a=1
        else: 
            a=2

    if a==1:
        print(message)
        print(len(message))
        mydata=[('temperature',message)]
        mydata=urllib.urlencode(mydata)
        path='http://localhost:8888/PHP/apps/index.php'
        req=urllib2.Request(path, mydata)
        page=urllib2.urlopen(req).read()
        print(page)
