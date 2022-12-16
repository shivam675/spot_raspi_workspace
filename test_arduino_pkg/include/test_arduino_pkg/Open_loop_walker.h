#ifndef OPEN_LOOP_WALKER_ROSCPP_LIBRARY_H
#define OPEN_LOOP_WALKER_ROSCPP_LIBRARY_H


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"
#include <sstream>
#include <string.h>
// #include "math.h"
#include <array>
#include <cmath>



class OpenLoopWalker
{
    // Access specifier
    public:
    // Init Params of the class
    float period = 1.0/8;    
    bool goal_reached = false;

    // std::array<int, 8> actions = {0, 1, 1, 1, 0, 0, 0, 0};
    std::array<float, 12> init_pose = {
        0.151, -0.904, 1.481,
        -0.151, -0.904, 1.481,
        0.151, -0.904, 1.481,
        -0.151, -0.904, 1.481
    };
    bool stay_still = false;
    float end_time = 0.0;
    //  End of init params



    // Member Functions()
    float evaluate_brakes_stage_coeff(float current_time, const std::array<float, 2> actions, float end_time=0.0, float end_val=0.0){
        float p = 0.8 + actions[1];

        if (end_time <= current_time <= p + end_time)
        {
            float val = 1 - (current_time - end_time);
            return val;
        }

        else{
            return end_val;
        }
    }


    float evaluate_gait_stage_coeff(float current_time, const std::array<float, 8> actions, float end_time=0.0){
        
        float p = 0.8 + actions[1];
        if (end_time <= current_time <= p + end_time)
        
        {
            return current_time;
        }

        else{
            return 1;
        }
    }

    const std::array<float, 12> open_loop_signal(float current_time_step, const std::array<float, 8> actions){

        float la = 0.1, fa = la*2;

        if (goal_reached)
        {
            float coeff = evaluate_brakes_stage_coeff(current_time_step, {0, 0}, end_time, 0.0);
            la *= coeff;
            fa *= coeff;

            if (coeff == 0.0)
            {
                stay_still = true;
            }

        }
        
        float start_coeff = evaluate_gait_stage_coeff(current_time_step, {0.0});
        la *= start_coeff;
        fa *= start_coeff;

        float l_extension = la * cos((2 * M_PI)/(period * current_time_step));
        float f_extension = fa * cos((2 * M_PI)/(period * current_time_step));

        std::array<float, 12> init_postion = init_pose;

        float l_swing = - l_extension;
        float swing = - f_extension;

        std::array<float, 12> pose = {
            0.0, l_extension + actions[0], f_extension + actions[1],
            0.0, l_swing + actions[2], swing + actions[3],
            0.0, l_swing + actions[4], swing + actions[5],
            0.0, l_extension + actions[6], f_extension + actions[7],

        };

        std::array<float, 12> action_signal;

        
        for (size_t i = 0; i < action_signal.size(); i++)
        {
            action_signal[i] = init_postion[i] + pose[i];
        }
        
        // action_signal[i] = 
        
        return action_signal;

    }
};

#endif

