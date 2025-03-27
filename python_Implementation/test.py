import serial
import numpy as np
import time

def main():
    port = serial.Serial('COM9',115200)

    ON_OFF = 0

    TX_Frame = np.array([0x01,0x04,0x01,0],np.uint8)

    TX_Frame[2] = np.uint8(ON_OFF)

    TX_Frame[3] = crc8(TX_Frame,3)
    port.write(TX_Frame)

    time.sleep(0.1)

    print(port.read_all())
    pass


def crc8(data:list[np.uint8],len:int)->np.uint8:
    """
    Calculate the CRC8 checksum for the given data.

    :param data: A list or bytes-like object containing the input data.
    :return: The CRC8 checksum as an integer.
    """
    crc = np.uint8(0)
    for byte in data:
        crc ^= byte
    return crc

if __name__ == '__main__':
    main()