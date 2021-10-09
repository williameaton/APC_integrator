## Assignment 3: Numerical Integration program 

### Overview:

This program facilitates numerical integration for systems of both linear and non-linear differential equations. 


### Version details: 

- Version:       1.0
- Author:        Will Eaton, Princeton University
- Contact:       *weaton@princeton.edu* 
- Last updated:  Oct 6th 2021 


### Build: 

- All functionality of the program is utilised through a single executable called *ode_solve*. This executable can be generated using the provided makefile using `make ode_solve`. 


### Running *ode_solve*: 
- *ode_solve* is capable of conducting numerical integration on both linear and non-linear systems of equations with a variety of integration methods. Integration is executed using the following command: <br> ```./ode_solve <model> <params> <ICs> <integrator> <timestep> <numsteps> ``` <br>

- Details of supported inputs and syntax are given in the following table: 

| Cmd Argument<br>[type] | Description                                                                                                                                                                 | Supported inputs                                                                                         |
|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------|
| Model <br>[str]        | System of equations to be solved                                                                                                                                            | "ddo" - Damped driven oscillator<br>"lv"  - Lotka-Voltera equations                                      |
| params <br>[str]       | Space-separated list of parameters <br>used to fully define the model within <br>a single "". <br><br>Parameters must be parsed in correct <br>order within a single string | TBC                                                                                                      |
| IC                     | TBC                                                                                                                                                                         | TBC                                                                                                      |
| integrator <br>[str]   | Numerical integration method                                                                                                                                                | "euler" - Forward Euler method<br>"rk4"   - 4th-order Runge-Kutta<br>"ab2"   - 2nd-order Adams-Bashforth |
| timestep <br>[double]  | Fixed timestep for integration                                                                                                                                              | Real positive floating point                                                                             |
| numsteps <br>[int]     | Number of integration timesteps                                                                                                                                             | Real positive integer                                                                                    |

- Example 1: <br>`$ ./ode_solve ddo "2.0 1.5 0.25 1.0" "3.0 1.5 0.0" euler 0.1 40`<br> conducts numerical integration using the Forward Euler method for a damped, driven oscillator with driving frequency (&omega; = 2.0 Hz) and amplitude (F = 1.5 m), damping factor (&beta; = 0.25) and fundamental frequency (&omega;<sub>0</sub> = 1.0 Hz). These aforementioned properties of the oscillatory are prescribed in the first string. The second string prescribes initial conditions x = 1.5, t = 3.0 with velocity 0.0 [m/s]. Finally, 0.1 and 40 are the timestep [s] and number of timesteps respectively. 



### Still to be implemented: 

- Complete parameter table in README.md 
- Write Example 2 for Lotka-Voltera equation system 
- ode_solve.cc 
- ode_solve.h 
- integrator-factory.cc
- integrator-factory.h
- ab2.cc
- ab2.h
- lv.cc
- lv.h


## Tasks in order: 
- Sort out user inputs 
- Write AB2 
- Write model factory 
- Write LV 
