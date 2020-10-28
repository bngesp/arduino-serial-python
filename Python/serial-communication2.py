##########################
# Author : Bassirou NGOM
# date : 04/01/2019
# licence: MIT
##########################


from serial import Serial
import urllib3
serial_port = Serial(port='/dev/cu.wchusbserial1410', baudrate=9600)
while True:
    message = serial_port.readline()
    message = message[:5]
    print(message)
    print(len(message))
    path='http://localhost:8888/PHP/apps/index.php'
    http = urllib3.PoolManager()
    http.request(
    	'GET',
    	path, 
    	fields={'temperature': message})
    

