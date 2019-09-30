import threading
import time
import RPi.GPIO as GPIO
from pygame import mixer
# Pins definitions
btn_pin = 4
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(btn_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
# Initialize pygame mixer
mixer.init()
# Load the sound
sound = mixer.Sound('prova.mp3')
# If button is pushed
m = 0
def abc():
   m = 0
try:
    while True:
       # If button is pressed, turn on LED and play sound
       current_state = GPIO.input(btn_pin)
       if (current_state == False) and (prev_state == True) and (mixer.get_busy() == False):
               t = threading.Timer(30.0, abc)
               t.start()
               m = m + 1
               print(m)
               if (m == 3):
                   sound.play()
       # Save state of switch to use in next iteration of the loop
       if mixer.get_busy() == True:
           m = 0
       prev_state = current_state
# When you press ctrl+c, this will be called
finally:
   GPIO.cleanup()