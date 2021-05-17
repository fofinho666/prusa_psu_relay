#!/usr/bin/python3

import serial
from serial.tools import list_ports
from argparse import ArgumentParser

#  find Seeed XIAO M0
def find_relay():
    ports = list(list_ports.comports())
    filtered = filter(lambda port: port.description == 'Seeed XIAO M0', ports)
    port = next(filtered, None)
    if not port:
        raise IOError("Relay not found")
    return serial.Serial(port.device)

parser = ArgumentParser()
parser.add_argument('operation', help='Which operation to execute: "on" or "off"')
parser.parse_args()

args = parser.parse_args()
operation = args.operation.lower()
relay = find_relay()

if operation == "on":
    relay.write("1".encode())
elif operation == "off":
    relay.write("0".encode())
else:
    raise IOError('Unknown operation: Only "on" or "off" are supported')

relay.close()