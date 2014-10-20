//
//  Motion.h
//  SacredGeometry1
//
//  Created by skymedical on 10/20/14.
//
//

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

typedef std::shared_ptr <class Motion> MotionRef; //Assigning our pointer MotionRef to class Motion 
class Motion {
public: Motion();
    void update();
    void draw();
    
    
private: float x_; float y_; int radius_;

};

