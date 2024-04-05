import csv

csv_file = open('nmea_data.csv', 'w', newline='')
csv_writer = csv.writer(csv_file)
csv_writer.writerow(['lat', 'lon', 'utm_x', 'utm_y'])
csv_writer.writerow(['lat', 'lon', 'utm_x', 'utm_xxxx'])