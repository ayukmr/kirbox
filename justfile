default: build upload

build:
  arduino-cli compile --fqbn arduino:avr:uno

upload:
  arduino-cli upload -p /dev/cu.usbmodem101 --fqbn arduino:avr:uno
