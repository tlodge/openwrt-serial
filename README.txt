Scripts to send/recv data over serial connection to ESP8266.

/dev/ttyS0 is the (internal) serial connection on the router. Baud 9600 transfer

stty -F /dev/ttyS0 9600

To read from ESP8266

cat < /dev/ttyS0

