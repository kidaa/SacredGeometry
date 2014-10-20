//
//  UserControl.h
//  SacredGeometry1
//
//  Created by skymedical on 10/20/14.
//
//

#pragma once
#include "cinder/params/Params.h"


class UserControl {
public:
    UserControl();
    void step();
    void display();
    void init();
    float mObjSize;
    //float Quatf:: mObjOrientation;
    cinder::vec3 mLightDirection;
    cinder::ColorA mColor;
    
    
};