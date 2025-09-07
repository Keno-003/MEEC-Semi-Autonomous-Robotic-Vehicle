# Semi-Autonomous-Robotic-Vehicle
C++ code for MEEC, a semi-autonomous Arduino-based vehicle with a claw mechanism. The code establishes interaction between the microcontroller and the other robot components (e.g motors, servos, and sensors). The repository also has code for the robot's autonomous movement and remote control feature.

Both files in the repository initialise the motors and buttons on the remote controller. The files also control the motors, instructing them to move in different ways for different movements. The motors were connected to wheels so we made the motors move like  a car. We made turns possible by turning off the motors on one side of MEEC. If we wanted a left turn, the left-sided motors would be switched off and the front right one would stay on. The opposite would be the case if MEEC needed to turn right. 

The Obstacle_Avoider_Program uses sensors to detect obstacles in front of MEEC. If the object is closer than 30 cm to the robot, MEEC turns right and checks if there is any object closer than 30cm to it. If there isn't, the robot proceeds forward. The algorithm for this automated movement runs continuously, allowing MEEC to avoid obstacles by itself.

The Remote_Control_and_Claw_Movement file initialises the servos for the claw movement and clamp functionality (to grip onto objects). This code works with a remote controller and doesn't allow for autonomous movement.
