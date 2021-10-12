
#include "ddo.h"
#include <string>
#include <vector>
#include <iostream>
#include "model-factory.h"
#include "integrator-factory.h"
#include <assert.h>  
#include "rk4.h"
#include "ab2.h"

class DDOscillator;
class Euler; 
class Model;
class Rk4; 
class Ab2; 
class Integrator;
class ModelFactory; 


// Class needs modifying to be flexible to the n of x - some iterative print/string appending 
void printState(double t, double *x, int dimen){
    
    printf("%15.8f", t);
    
    for (int i=0; i<dimen; i++){
        printf(" %15.8f", x[i]);
    }
    printf("\n");
}


class Inputs{
    // Example input: ./ode_solve ddo "2.0 1.5 0.25 1.0" "3.0 1.5 0.0" euler 0.1 40
    // Should therefore be argc = 7

    public: 
        Inputs(){
            // Allocate memory for Params and ICs 
            params = new double[4];
            ICs = new double[3];
        };
        
        ~Inputs(){

              delete [] params;
              delete [] ICs;
        };


        int extractInputs(int argc_, char **argv_){

            checkArgs_(argc_); // Check inpujt is okay 
            
            // Convert each element of argv_ to a string object in a vector args 
            std::vector<std::string> args(argc_);     
            for (int i = 0; i < argc_; ++i){
                args[i] = argv_[i];
            }

            // Assign various strings to members using conversion methods
            model_str = args[1];
            processString_(params, args[2], 4);
            processString_(ICs, args[3], 3);
            integrator_str = args[4]; 
            dt = std::stod(args[5]);
            timesteps = std::stoi(args[6]);

            return 0;
        }; 

        double initICs(double *x, int dimen){
            double t = ICs[0];
            
            for (int i=0; i<dimen; i++){
                x[i] = ICs[i+1];
            }
            return t;
        }


        std::string model_str; // Array holding model string
        std::string integrator_str; // Array holding integrator strings 
        double *params; 
        double *ICs; 
        double dt; 
        int timesteps; 


    private: 

        int checkArgs_(int num_args_){
            // Check number of args is 7 
            assert(num_args_==7); 
            return 0;
        }


        int processString_(double *out_array, std::string ipt_str, int dim){
            int position;

            for (int k=0; k<dim; k++){
                position = ipt_str.find(" "); // find first 
                out_array[k] = std::stod(ipt_str.substr(0, position));
                ipt_str = ipt_str.substr(position+1); // Update for next loop
            }
            return 0;
        }

};




int main(int argc, char **argv){

    // Get parameters from the user and sort 
    Inputs user_i; 
    user_i.extractInputs(argc, argv); 

    // Generate model using factory 
    ModelFactory model_factory; 
    Model *model = model_factory.createModel(user_i.model_str, user_i.params); 

    // Generate integrator using factory  ********
    Euler integrator(user_i.dt, *model); 

    // Initialise conditions 
    double x[model->dimen()]; // Needs to be set to the initial conditions 
    double t = user_i.initICs(x, model->dimen());


    printState(t, x, model->dimen());
    // Loop: run step function of the model - need to print at each timestep --> function within integrator or seperate class? 
    for (int i=0; i<user_i.timesteps; ++i){
        integrator.Step(t, x);
        t += user_i.dt;
        printState(t, x, model->dimen());
    }

    // Destruction of any classes - possibly a factory to do this but might not be necessary? 
    //model->~Model();
    // integrator.~Euler();

    return 0;
}





