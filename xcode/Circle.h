//
//  Circle.h
//  SaturdayOne
//
//  Created by Rena Anakwe on 9/13/14.



#pragma once

class Circle {
public: //What you can see outside of class
    
    Circle(); //Constructor
    ~Circle(); //Destructor
    
    void draw();
    int getX();
    int getY();
    int getRadius();
    
    
private: //What you can only see inside my class
    int mX, mY;
    int mRadius; //You can declare it's attributes
    
    
    
};