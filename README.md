# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Problem Statement
Implemented a PID controller in C++ to maneuver the car around a race track.

## PID controller
Udacity's simulator provides the cross track error (CTE) and speed. The CTE is used as input to the PID control which controls the steering angle of the vehicle.

A proportional–integral–derivative controller (PID controller) is a control loop feedback mechanism that continuously calculates an error value as the difference between a desired state and true state and applies a correction based on proportional (P), integral (I), and derivative (D) error terms. The control control variable is set as a sum of the three error terms multiplied by scalar constants. The proportional term increases action in relation on the error and drives the error to zero, but leads to oscillations if the magnitude of error is large. The differential term is introduced to reduce the oscillations. The integral term increases action in relation to the error and also how long it has persisted.

## Controlling Steering angle
The steering angle is calculated as a function of CTE as:

steer_value = -Kp.cte - Ki.int_cte - Kd.diff_cte

The error coefficients (Kp, Ki, Kd) were tuned manually stating from the values used in the lessons. The coefficients are set as Kp=0.15, Ki=0.0008, Kd=2.5.
A large value of Kp causes the steering angle to oscillate. Kp and Kd together largely contribute to the smooth and steady steering response.

The steering angle is further filtered using an Exponential Moving Average filter:

steer_ang_filt = (1-alpha).steer_value + alpha.prev_steer_filt

Where alpha, the filter coefficient is set to 0.05.

With constant throttle of 0.35, and the coefficients as described above, the car drives very well around the race track.

**With Constant throttle:**

[![Constant Throttle](http://img.youtube.com/vi/eObcKcxbo48/0.jpg)](http://www.youtube.com/watch?v=eObcKcxbo48)

### Variable Throttle
Using constant throttle drives around the race track at a conservative speed (<40mph). By tuning the throttle based on the desired speed and CTE, the car drives faster when the conditions are favorable.

**With Variable throttle:**

[![Variable Throttle](http://img.youtube.com/vi/lRloj9aGICY/0.jpg)](http://www.youtube.com/watch?v=lRloj9aGICY)

---
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
