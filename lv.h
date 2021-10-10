#ifndef LV_H_
#define LV_H_

#include "model.h"

class Lv: public Model
{   
public:
    Lv(double *params);
    ~Lv();

    int rhs(double t, const double *x, double *fx) const;
    int dimen() const{
        return dimen_;
    }; 

private: 
    double alpha_, beta_, gamma_, delta_;
    static const int dimen_ = 2; 
};


#endif // LV_H_