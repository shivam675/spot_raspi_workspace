from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['test_arduino_pkg'],
    package_dir={'': 'include'}
)

setup(**d)