#! /usr/bin/env python3

import warnings
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from rclpy.qos import QoSProfile
from pyproj import Proj, transform

warnings.filterwarnings('ignore')

class NMEASubscriber(Node):
    def __init__(self):
        super().__init__('nmea_subscriber')
        qos_profile = QoSProfile(depth=10)
        self.nmea_subscription = self.create_subscription(String, 'nmea', self.nmea_CB, qos_profile)
        self.line = None
        
    def nmea_CB(self, msg):
        self.line = msg.data
        self.gps_to_utm()
    
    def gps_to_utm(self):
        line = self.line.split(',')
        
        lat_deg = int(float(line[2]) // 100)
        lat_min = float(line[2]) % 100
        lon_deg = int(float(line[4]) // 100)
        lon_min = float(line[4]) % 100

        lat = lat_deg + lat_min / 60
        lon = lon_deg + lon_min / 60
        
        wgs84 = Proj(init='epsg:4326')
        utm = Proj(init='epsg:32652')
        
        utm_north, utm_east = transform(wgs84, utm, lon, lat)
        
        print('---------- GGA DATA ----------')
        print(f'GGA.raw_data :', self.line, end="")
        print(f'GGA.message_id :', line[0][1:])
        print(f'GGA.utc :', line[1])
        print(f'GGA.lat :', utm_north)
        print(f'GGA.lat_dir :', line[3])
        print(f'GGA.lon :', utm_east)
        print(f'GGA.lon_dir :', line[5])
        print(f'GGA.quality :', line[6])
        print(f'GGA.num_satellite :', line[7])
        print(f'GGA.HDOP :', line[8])
        print(f'GGA.alt :', line[9])
        print(f'GGA.alt_unit :', line[10])
        print(f'GGA.sep :', line[11])
        print(f'GGA.sep_unit :', line[12])
        print(f'GGA.diff_age :', line[13])
        print(f'GGA.diff_station :', int(line[14][0:4]))
        print(f'GGA.check_sum :', line[14][5:])

def main(args=None):
    rclpy.init(args=args)
    nmea_subscriber = NMEASubscriber()
    try:
        rclpy.spin(nmea_subscriber)
    except KeyboardInterrupt:
        nmea_subscriber.destroy_node()
        rclpy.shutdown()
        
if __name__ == '__main__':
    main()
        