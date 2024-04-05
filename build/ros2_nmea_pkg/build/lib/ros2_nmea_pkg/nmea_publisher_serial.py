#! /usr/bin/env python3

import os
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from std_msgs.msg import String

class NMEAPublisher(Node):
    def __init__(self):
        super().__init__('nmea_publisher')
        self.current_dir = os.getcwd()
        self.file_path = self.current_dir + '/nmea.txt'
        self.lines = None
        self.data_line = None
        self.read_txt()
        qos_profile = QoSProfile(depth=10)
        self.nmea_publisher = self.create_publisher(String, 'nmea', qos_profile)
        msg = String()
        self.publish_message(msg)
        
    def read_txt(self):
        with open(self.file_path, 'r') as nmea_file:
            self.lines = nmea_file.readlines()

    def publish_message(self, msg):
        for i in range(len(self.lines)):
            if self.lines[i][3:6] == 'GGA':
                self.data_line = self.lines[i]
                msg.data = self.data_line
                self.nmea_publisher.publish(msg)
                
def main(args=None):
    rclpy.init(args=args)
    nmea_publisher = NMEAPublisher()
    try:
        rclpy.spin(nmea_publisher)
    except KeyboardInterrupt:
        nmea_publisher.destroy_node()
        rclpy.shutdown()
        
if __name__ == '__main__':
    main()
        
        
    
