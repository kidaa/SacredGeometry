//
//  star.h
//  SacredCinderBot
//
//  Created by Isi on 10/17/14.
//
//

#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"


class flOfLife{
public:
    
    flOfLife();
    
    flOfLife( ci::vec2 Pos, float Rad, float SideNumb, ci::vec2 Window);
    
    
    void addPoints();
    void drawRound();
    void drawSqua();
    void drawTri();
    void update();
    
    ci::vec2    mPos;
    ci::vec2    mWindow;
    
    
    float       mRad;
    float       mSideNumb;
    float       mTheta;
    float       mRand;
    
    std::vector<ci::vec2> mPositions;
    
};