//
//  star.cpp
//  SacredCinderBot
//
//  Created by Isi on 10/17/14.
//
//

#include "cinder/app/AppBasic.h"
#include <stdio.h>
#include <math.h>
#include "cinder/Vector.h"
#include "star.h"

using namespace ci;
using namespace ci::app;
using namespace std;

flOfLife::flOfLife()
{
    
}

flOfLife::flOfLife( ci::vec2 Pos, float Rad, float SideNumb, ci::vec2 Window)
{
    
    mPos      = Pos;
    mRad      = Rad;
    mSideNumb = SideNumb;
    mTheta    = -M_PI_2;
    mWindow   = Window;
    mRand     = randInt(mSideNumb/3, mSideNumb*2);
    
}


void flOfLife::addPoints(){
    
    for ( int i = 0; i < flOfLife::mSideNumb; i++){
        mPositions.push_back(mPos);
    }
    
}

void flOfLife::drawRound(){
    
    //Translate to center of the window:
    gl::translate(mWindow.x/2, mWindow.y/2);
    
    //Find the angle between each point:
    float deltaTheta = (M_PI * 2.0) / mSideNumb;
    
    //Iterate over each point, color and
    //place circle at that point:
    for (int i = 0; i < mSideNumb; i++){
        
        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
        
        gl::color( 1, 1, 0 );
        gl::drawStrokedCircle(mPositions[i], 100);
        
    }
    
}

void flOfLife::update(){
    
}
//void flOfLife::drawSqua(){
//    gl::translate(mWindow.x/2, mWindow.y/2);
//    float deltaTheta = (M_PI * 2.0) / mSideNumb;
//
//    for (int i = 0; i < mSideNumb; i++){
//
//        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
//        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
//
//        gl::color( 1, 1, 0 );
//        gl::rotate(1);
//        gl::drawStrokedCircle(mPositions[i], 100);
//
//        gl::drawStrokedRect( Rect(mPositions[i]*2.0f, mPositions[i]*2.0f, 0.8);
//
//    }
//}

void flOfLife::drawTri(){
    gl::translate(mWindow.x/2, mWindow.y/2);
    float deltaTheta = (M_PI * 2.0) / mSideNumb;
    
    for (int i = 0; i < mSideNumb; i++){
        
        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
        
        vec2 tA = mWindow * vec2( 0,  -0.25 );
        vec2 tB = mWindow * vec2( -0.25, 0.25 );
        vec2 tC = mWindow * vec2( 0.25, 0.25 );
        
        gl::rotate(1);
        
        gl::color(1, 1, 0);
        gl::drawSolidTriangle( tA, tB, tC );
    }
    
    for (int i = 0; i < mSideNumb; i++){
        
        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
        
        vec2 tA = (mWindow * 0.80f) * vec2( 0,  -0.25 );
        vec2 tB = (mWindow * 0.80f) * vec2( -0.25, 0.25 );
        vec2 tC = (mWindow * 0.80f) * vec2( 0.25, 0.25 );
        
        gl::rotate(1);
        
        gl::color(0, 0, 0);
        gl::drawSolidTriangle( tA, tB, tC );
    }
    //    for (int i = 0; i < mSideNumb; i++){
    //    vec2 nA = mPositions[i] * vec2( 0.4,  0.15 );
    //    vec2 nB = mPositions[i] * vec2( 0.15, 0.65 );
    //    vec2 nC = mPositions[i] * vec2( 0.65, 0.65 );
    //
    //        gl::color(0, 0, 0);
    //        gl:: drawSolidTriangle( nA, nB, nC);
    //    }
    
    
}



