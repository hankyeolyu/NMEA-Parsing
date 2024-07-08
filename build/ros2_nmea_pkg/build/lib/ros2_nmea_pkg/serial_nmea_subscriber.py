#! /usr/bin/env python3

import warnings
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from rclpy.qos import QoSProfile
from pyproj import Proj, transform
import pandas as pd

warnings.filterwarnings('ignore')

class SerialNMEASubscriber(Node):
    def __init__(self):
        super().__init__('serial_nmea_subscriber')
        qos_profile = QoSProfile(depth=10)
        self.serial_nmea_subscription = self.create_subscription(String, 'nmea', self.nmea_CB, qos_profile)
        self.df = pd.DataFrame(columns=['lat', 'lon', 'utm_x', 'utm_y', 'utc'])
        self.line = None
        
    def nmea_CB(self, msg):
        self.line = msg.data
        self.gps_to_utm()
    
    def gps_to_utm(self):
        line = self.line.split(',')
        try:
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
            print(f'GGA.raw_data :', self.line)
            print(f'GGA.message_id :', line[0][1:])
            print(f'GGA.utc :', line[1])
            print(f'GGA.lat :', lat)
            print(f'GGA.lat_dir :', line[3])
            print(f'GGA.lon :', lon)
            print(f'GGA.lon_dir :', line[5])
            print(f'GGA.quality :', line[6])
            print(f'GGA.num_satellite :', line[7])
            print(f'GGA.HDOP :', line[8])
            print(f'GGA.alt :', line[9])
            print(f'GGA.alt_unit :', line[10])
            print(f'GGA.sep :', line[11])
            print(f'GGA.sep_unit :', line[12])
            print(f'GGA.diff_age :', line[13])
            diff_check = line[14].split('*')
            print(f'GGA.diff_station :', diff_check[0])
            print(f'GGA.check_sum :', diff_check[1])
            print(f'GGA.utm_x :', utm_north)
            print(f'GGA.utm_y :', utm_east)
        
            tmp_df = pd.DataFrame({'lat':[lat],'lon':[lon],'utm_x':[utm_north],'utm_y':[utm_east], 'utc':[line[1]]})
            self.df = pd.concat([self.df, tmp_df])
        except ValueError: # 비어있는 데이터가 들어오는 경우에 대한 예외 처리
            pass
        
def main(args=None):
    rclpy.init(args=args)
    serial_nmea_subscriber = SerialNMEASubscriber()
    try:
        rclpy.spin(serial_nmea_subscriber)
    except KeyboardInterrupt:
        serial_nmea_subscriber.df.to_csv('nmea_data_2.csv', index=False)
        serial_nmea_subscriber.destroy_node()
        rclpy.shutdown()
        
if __name__ == '__main__':
    main()
        