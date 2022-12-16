
#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "string.h"







int main(int argc,char **argv){
    std::string s = "Initiated ...";
    std::string a;

    std::cout << "Enter your Text Here: ";
    std::cin >> a;

    std::cout << s + " " + a << std::endl;

    return 0;
}


