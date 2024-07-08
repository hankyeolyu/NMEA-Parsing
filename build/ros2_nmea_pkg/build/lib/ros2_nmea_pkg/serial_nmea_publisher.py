#! /usr/bin/env python3

import rclpy
import serial
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String

class SerialNMEAPublisher(Node):
    def __init__(self):
        super().__init__('serial_nmea_publisher')
        self.port = '/dev/ttyACM0' # Arduino Serial 사용 시
        self.usb_port = '/dev/ttyUSB0' # MRP 2000 사용 시
        self.baudrate = 115200
        self.ser = serial.Serial(self.usb_port, self.baudrate, timeout=1)
        self.qos_profile = QoSProfile(depth=10)
        self.serial_nmea_publisher = self.create_publisher(String, 'nmea', self.qos_profile)
        
    def receive_data(self):
        while True: 
            data_line = self.ser.readline().decode('UTF-8').strip()
            if data_line[3:6] == 'GGA':
                break
        return data_line

    def publish_message(self):
        msg = String()
        data_line = self.receive_data()
        msg.data = data_line
        self.serial_nmea_publisher.publish(msg)
    
    def run(self):
        while not self.ser.closed:
            self.publish_message()
                
def main(args=None):
    rclpy.init(args=args)
    serial_nmea_publisher = SerialNMEAPublisher()
    try:
        serial_nmea_publisher.run()
    except KeyboardInterrupt:
        serial_nmea_publisher.ser.close()
        serial_nmea_publisher.destroy_node()
        rclpy.shutdown()
        
if __name__ == '__main__':
    main()
        
        
    
