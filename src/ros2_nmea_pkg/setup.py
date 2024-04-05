from setuptools import setup

package_name = 'ros2_nmea_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hankyeolyu',
    maintainer_email='hankyeolyu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'nmea_publisher = ros2_nmea_pkg.nmea_publisher:main',
            'nmea_subscriber = ros2_nmea_pkg.nmea_subscriber:main',
            'serial_nmea_publisher = ros2_nmea_pkg.serial_nmea_publisher:main',
            'serial_nmea_subscriber = ros2_nmea_pkg.serial_nmea_subscriber:main',
        ],
    },
)
