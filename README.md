# car_ackermann
Ackermann car with lidar on Gazebo 

Author: Hugo Reubrecht 

# Prerequisites
Ros noetic version desktop 


Create your Ros workspace and clone this reposotory in your src folder.

Launch the simulation
```
roslaunch car_ackermann_gazebo car_ackermann_world.launch
```
Launch teleop_twist_keyboard (install it if necessary)
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=robot_command
```
Edit : the steering control is not perfect yet need to adapt some joints on the URDF model
