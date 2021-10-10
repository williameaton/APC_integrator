# Assignment 3: Numerical Integration program 

## Overview:

This program facilitates numerical integration for systems of both linear and non-linear differential equations. Currently-supported systems of equations are: 

#### <ins>Linear, damped driven oscillator:</ins>

A linear, damped driven oscillator of displacement (q) is defined by:

 &part;<sup>2</sup><sub>t</sub> q  + 2&beta; &part;<sub>t</sub>q  + &omega;<sub>0</sub><sup>2</sup> q = f(x,t),

 in which &beta; is the damping factor and &omega;<sub>0</sub> is the fundamental frequency. The driving force is a cosine with angular frequency &omega; and amplitude F. 

#### <ins>Lotka-Volterra equations:</ins>

This non-linear system of equations is used to describe interactions between predetory (Y) and prey populations (X).

1) &part;<sub>t</sub>X = &alpha;X - &beta;XY 
2) &part;<sub>t</sub>Y = &gamma;XY - &delta;Y 

in which &alpha; and &beta; are prey birth and death rates respectively, while &gamma; and &delta; are preditor reproduction and death rates. 

Either set of equations can currently be integrated using: 
1) Forward Euler method
2) 4th-order Runge-Kutta method
3) 2nd-order Adams-Bashforth method (using RK4 for first step)








## Version details: 

- Version:       1.4
- Author:        Will Eaton, Princeton University
- Contact:       *weaton@princeton.edu* 
- Last updated:  Oct 10th 2021 


## Build: 

- All functionality of the program is utilised through a single executable called *ode_solve*. This executable can be generated using the provided makefile using `make ode_solve`. 


## Running *ode_solve*: 
- *ode_solve* is capable of conducting numerical integration on both linear and non-linear systems of equations with a variety of integration methods. Integration is executed using the following command: <br> ```./ode_solve <model> <params> <ICs> <integrator> <timestep> <numsteps> ``` <br>

- Details of supported inputs and syntax are given in the following table: 

| **Cmd Argument<br>[type]** | **Description**                                                                                                                                                                                                                                                          | **Supported inputs**                                                                                                                                                                              |
|----------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Model <br>[str]            | System of equations to be solved                                                                                                                                                                                                                                         | "ddo" - Damped driven oscillator<br>"lv"  - Lotka-Voltera equations                                                                                                                               |
| params <br>[str]           | Space-separated list of parameters <br>used to fully define the model within <br>a single "...". <br><br>Parameters must be parsed in correct <br>order within a single string.                                                                                          | <ins>For DDO:</ins><br><br>"&omega;, F, &beta;, &omega;<sub>0</sub>"<br><br><ins>For LV:</ins><br>"&alpha;, &beta;, &gamma;, &delta";<br><br>where all above variables are floating point values. |
| IC [str]                   | Initial conditions specifying start <br>time, and initial values for state variables.<br>State variables are Displacement, Velocity<br>for DDO, and Prey, Preditor populations for <br>LV.<br><br>Parameters must be parsed in correct <br>order within a single string. | "time state_var1 state_var2"<br><br>where all above variables are floating <br>point values                                                                                                       |
| integrator <br>[str]       | Numerical integration method                                                                                                                                                                                                                                             | "euler" - Forward Euler method<br>"rk4"   - 4th-order Runge-Kutta<br>"ab2"   - 2nd-order Adams-Bashforth                                                                                          |
| timestep <br>[double]      | Fixed timestep for integration                                                                                                                                                                                                                                           | Real positive floating point                                                                                                                                                                      |
| numsteps <br>[int]         | Number of integration timesteps                                                                                                                                                                                                                                          | Real positive integer                                                                                                                                                                             |

- Example 1: <br>`$ ./ode_solve ddo "2.0 1.5 0.25 1.0" "3.0 1.5 0.0" euler 0.1 40`<br> conducts numerical integration using the Forward Euler method for a damped, driven oscillator with driving frequency (&omega; = 2.0 Hz) and amplitude (F = 1.5 m), damping factor (&beta; = 0.25) and fundamental frequency (&omega;<sub>0</sub> = 1.0 Hz). These aforementioned properties of the oscillatory are prescribed in the first string. The second string prescribes initial conditions x = 1.5, t = 3.0 with velocity 0.0 [m/s]. Finally, 0.1 and 40 are the timestep [s] and number of timesteps respectively. 

- Example 2: <br> `$ ./ode_solve lv "1.0 0.2 0.1 0.2" "0.0 1.0 2.0" ab2 0.0005 100000 > lv_data.txt ` <br> conducts integration using the Adams-Bashforth method for the Lotka-Voltera equations using the following: &alpha;=1.0,  &beta;=0.2,  &gamma;=0.1,  &delta;=0.2,  t<sub>0</sub>=0.0,  X<sub>0</sub>=1.0,  Y<sub>0</sub>=2.0 and &Delta;t = 0.0005 seconds with 100000 timesteps. 



## Still to be implemented: 

- integrator-factory.cc
- integrator-factory.h


## Tasks in order: 
- Write model factory 
