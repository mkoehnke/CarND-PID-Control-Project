# CarND PID-Controller

This project implements a PID controller in C++ to maneuver a vehicle around a track using the Udacity Term 2 Simulator, which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).

### Observations

#### Proportional Component (P)

- responsible for for steering in direction of the track reference to minimize the crosstrack error
- overshoots reference (x-axis)
- higher values of the coefficient (e.g. 2.0) tend to increase the weaving of the car: [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-p-higher-value.mov)
- lower values of the coefficient (e.g. 0.0) tend to increase the time to adjust and hardly change the steering direction: [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-p-lower-value.mov)

#### Integral Component (I)

- helps to counter systematic bias (e.g. misaligned wheels)
- steers with a greater angle if there is a permanent error by taking past integrals of CTE into account
- higher values of the coefficient (e.g 0.5) tend to overshoot the reference by taking the systematic bias too much into account. Car immediately goes off track: [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-i-higher-value.mov)
- lower values of the coefficient (e.g. 0.0) tend to make the car's tyres sometimes touch the edge of the track: [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-i-lower-value.mov)

#### Differential Component (D)

- takes CTE for calculation into account
- steering in the direction of the reference reduces the CTE
- if the CTE is small enough, the car will counter-steer to avoid overshooting the reference
- higher values of the coefficient (e.g. 15) tend to decrease the smoothness of the steering (instead very abrubt + strong angle): [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-d-higher-value.mov)
- lower values of the coefficient (e.g. 1.5) tend to prevent the car from counter-steering "in time" so it goes of the track immediately: [Link to video](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/pid-d-lower-value.mov)

### Hyper-Parameter Tuning

The **P (0.1)**, **I (0.0025)** and **D (3.5)** coefficients where choosen manually by trial and error.

## Installation

Install the uWebSocketIO using the following command:

```
sh install-mac.sh
```

Compile the source code by entering the following commands:

```
mkdir build
cd build
cmake ..
make
./pid
```

![PID Simulator](https://github.com/mkoehnke/CarND-PID-Control-Project/raw/master/resources/simulator.png)

