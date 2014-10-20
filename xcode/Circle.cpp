//
//  Circle.cpp
//  SaturdayOne
//
//  Created by Rena Anakwe on 9/13/14.
//
//

#include "Circle.h"
#include "cinder/gl/gl.h"

Circle::Circle()
: mX( 0 ), mY( 0 ), mRadius( 10 )

{
    
}

Circle::~Circle()
{
    
}

int Circle::getX()
{
    
    return mX;
}

int Circle::getY()
{
    return mY;
}

int Circle::getRadius()
{
    return mRadius;
}

void Circle::draw()
{
    cinder::gl::drawSolidCircle( ci::vec2( mX, mY ), mRadius) ;
    
    
}