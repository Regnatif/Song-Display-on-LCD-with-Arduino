import serial
from SwSpotify import spotify

arduino_uno = serial.Serial('com3', 9600)
old_song = " "

while True:
    current_song = spotify.song()

    if current_song != old_song:
        arduino_uno.write(b'*')
        arduino_uno.write(spotify.artist().encode())
        arduino_uno.write(b',')
        arduino_uno.write(spotify.song().encode())
        arduino_uno.write(b':')

    old_song = current_song