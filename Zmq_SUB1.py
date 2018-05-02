import zmq  
import time  
import sys   
import thread
  
# Socket to talk to server  
context = zmq.Context()  

exit = True

socket1 = context.socket(zmq.SUB)  
socket1.connect ("tcp://192.168.1.103:9060")  
socket1.setsockopt(zmq.SUBSCRIBE, "lux1")  

socket2 = context.socket(zmq.SUB)  
socket2.connect ("tcp://127.0.0.1:9062")  
socket2.setsockopt(zmq.SUBSCRIBE, "lux2")  

socket3 = context.socket(zmq.SUB)  
socket3.connect ("tcp://127.0.0.1:9063")  
socket3.setsockopt(zmq.SUBSCRIBE, "lux3")  

socket4 = context.socket(zmq.SUB)  
socket4.connect ("tcp://127.0.0.1:9065")  
socket4.setsockopt(zmq.SUBSCRIBE, "lux4")  

socket5 = context.socket(zmq.SUB)  
socket5.connect ("tcp://127.0.0.1:9066")  
socket5.setsockopt(zmq.SUBSCRIBE, "lux5")  

socket6 = context.socket(zmq.SUB)  
socket6.connect ("tcp://127.0.0.1:9068")  
socket6.setsockopt(zmq.SUBSCRIBE, "lux6")  

i = 0
def recv1():
    while exit:
        string = socket1.recv()  
        if i%6 == 1:
            print(string)
            #contents = string.split()[1:-2]
            #print(contents)
            print('\n****************************\n*************************************************************************\n')

def recv6():
    while exit:
        string = socket6.recv()  
        if i%6 == 2:
            print(string)
            print('\n****************************\n*************************************************************************\n')
        time.sleep(0.5)

def recv2():
    while exit:
        string = socket2.recv()  
        if i%6 == 3:
            print(string)
            print('\n****************************\n*************************************************************************\n')
        time.sleep(0.5)

def recv3():
    while exit:
        string = socket3.recv()  
        if i%6 == 4:
            print(string)
            print('\n****************************\n*************************************************************************\n')
        time.sleep(0.5)

def recv4():
    while exit:
        string = socket4.recv()  
        if i%6 == 5:
            print(string)
            print('\n****************************\n*************************************************************************\n')
        time.sleep(0.5)

def recv5():
    while exit:
        string = socket5.recv()  
        if i%6 == 0:
            print(string)
            print('\n****************************\n*************************************************************************\n')
        time.sleep(0.5)

thread.start_new_thread(recv1,())
#thread.start_new_thread(recv2,())
#thread.start_new_thread(recv3,())
#thread.start_new_thread(recv4,())
#thread.start_new_thread(recv5,())
#thread.start_new_thread(recv6,())
while True:
    i = (i + 1) % 9999
    time.sleep(1)

exit = False
