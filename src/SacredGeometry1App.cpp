//Sacred Geometry API by Rena Anakwe & Isioma Azu
//Art of Graphics Programming 2014
//ITP NYU Taught by Patrick Hebron

//SacredGeometry1App.cpp

//Built-In Classes
#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Shader.h"
#include "cinder/Vector.h"
#include "cinder/Utilities.h"
#include "cinder/params/Params.h"

#include "cinder/Rand.h"
#include "cinder/CinderMath.h"



//Created Classes
#include "star.h"
#include "Circle.h"
#include "Motion.h"


//Namespaces
using namespace ci;
using namespace ci::app;
using namespace std;

//Application's Main Class
class SacredGeometry1App : public AppNative {
  public:
	void setup();
    void prepareSettings(Settings * settings);
    void keydown( KeyEvent event );
    //void resize();
    //void update();
	void draw();


//Applications' Variables

    
    CameraPersp				mCam;
    mat4					mRotation;
    params::InterfaceGlRef	mParams;
    
public:
    flOfLife mrou;
    flOfLife mtri;
    Motion m;
    vec2 window;
    Color mColor;
    bool mMousePressed;
    bool mTrackingMouse;
    
    
};


//Main Class Functions
void SacredGeometry1App::prepareSettings(Settings * settings)
{
    settings->setWindowSize( 1024, 768 );
    settings->setFullScreen( true );
    settings->setResizable( true );
    settings->setTitle( "Sacred Geometry Viewer" );
    settings->setFrameRate( 60.0f );
    
}


void SacredGeometry1App::setup()
{
    //Window for Star
    vec2 window = static_cast<vec2>( getWindowSize() );
    std::cout << window << std::endl;
    
    mrou = flOfLife( (window/2.0f), 100, 20, window );
    mtri = flOfLife( (window), 100, 10, window );
    
    mrou.addPoints();
    mtri.addPoints();
    
 }

void SacredGeometry1App::keydown( KeyEvent event )
{

}


//void SacredGeometry1App::resize()
//{
//    mCam.setPerspective( 60.f, getWindowAspectRatio(), 1.0f, 1000.0f );
//    gl::setMatrices( mCam );
//}



//void SacredGeometry1App::update()
//{
//
//}

    void SacredGeometry1App::draw()
{
    //clear the screen
    gl::clear( Color( 0, 0, 0 ) );
    
    
//    gl::pushMatrices();
//    mtri.drawTri();
    //    gl::rotate(0.1);
//    gl::popMatrices();
    
    gl::pushMatrices();
    mrou.drawRound();
    gl::popMatrices();
    
    
    
}


CINDER_APP_NATIVE( SacredGeometry1App, RendererGl )
