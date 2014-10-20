//Sacred Geometry API by Rena Anakwe & Isioma Azu
//Art of Graphics Programming 2014
//ITP NYU Taught by Patrick Hebron

//SacredGeometry1App.cpp

//Built-In Classes
#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Shader.h"
#include "cinder/gl/Batch.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/ImageIo.h"
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
    void resize();
    void update();
	void draw();
    //void randomSpline();
    void makeGeom();

//Applications' Variables

    
    CameraPersp				mCam;
    bool					mDrawNormals, mDrawWireframe, mCaps, mUseSpline;
    gl::BatchRef			mBatch, mNormalsBatch;
    gl::BatchRef			mSplineBatch;
    gl::GlslProgRef			mGlsl;
    Font					mFont;
    mat4					mRotation;
    char					mCurrentChar;
    float					mApproximation, mDepth;
    int						mSubdivisions;
    BSpline3f				mSpline;
    
    params::InterfaceGlRef	mParams;
    
public:
    flOfLife mFlower;
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
    window = getWindowSize();
    std::cout << window << std::endl;
    mFlower = flOfLife( window/2.0f, 100, 8, window );
    mFlower.addPoints();
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    gl::enableFaceCulling();
    
    mDrawNormals = false;
    mDrawWireframe = false;
    mUseSpline = true;
    mCaps = true;
    mApproximation = 2.5f;
    mDepth = 2.2f;
    mSubdivisions = 30;
    mParams = params::InterfaceGl::create( getWindow(), "App parameters", toPixels( ivec2( 200, 400 ) ) );
    mParams->addParam( "Approximation", &mApproximation ).min( 0.1f ).max( 20.0f ).step( 0.1f ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Depth", &mDepth ).min( 0.01f ).max( 7.0f ).step( 0.25f ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Subdivisions", &mSubdivisions ).min( 1 ).max( 30 ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Spline", &mUseSpline ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Caps", &mCaps ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Wireframe", &mDrawWireframe ).updateFn( [=] { makeGeom(); } );
    mParams->addParam( "Draw Normals", &mDrawNormals ).updateFn( [=] { makeGeom(); } );
    
    mCam.lookAt( vec3( 30, 20, 40 ), vec3( 0 ) );
    
    mGlsl = gl::GlslProg::create( loadAsset( "shader.vert" ), loadAsset( "shader.frag" ) );
    
    mFont = Font( "Georgia", 32 );
    mCurrentChar = '&';
    //randomSpline();
    makeGeom();
    
    mGlsl->bind();
    
  
    
}

void SacredGeometry1App::keydown( KeyEvent event )
{
    mCurrentChar = event.getChar();
    //randomSpline();
    makeGeom();
}

void SacredGeometry1App::makeGeom()
{
    // get the shape for this character
    Shape2d shape = mFont.getGlyphShape( mFont.getGlyphChar( mCurrentChar ) );
    auto bounds = shape.calcPreciseBoundingBox();
    shape.transform( MatrixAffine2f::makeTranslate( -bounds.getCenter() ) );
    
    // this remaps the TEX_COORD_0s to color; it has to be so explicit because VC++ balks about ambiguous calls
    std::function<Colorf(vec3)> texCoordToColor = []( vec3 v ) ->Colorf { return Colorf( v.x, v.y, v.z ); };
    
    if( mUseSpline ) {
        auto extrudeSource = geom::ExtrudeSpline( shape, mSpline, mSubdivisions, mApproximation ).caps( mCaps );
        mBatch = gl::Batch::create( geom::ColorFromAttrib( extrudeSource, geom::TEX_COORD_0,
                                                          texCoordToColor ), mGlsl );
        
        mNormalsBatch = gl::Batch::create( geom::VertexNormalLines( extrudeSource, 3.0f ), gl::getStockShader( gl::ShaderDef().color() ) );
        mSplineBatch = gl::Batch::create( geom::BSpline( mSpline, 100.0f ), gl::getStockShader( gl::ShaderDef().color() ) );
    }
    else {
        auto extrudeSource = geom::Extrude( shape, mDepth, mApproximation ).caps( mCaps ).subdivisions( mSubdivisions ).enable( geom::TEX_COORD_0 );
        // this remaps the TEX_COORD_0s to color
        mBatch = gl::Batch::create( geom::ColorFromAttrib( extrudeSource, geom::TEX_COORD_0,
                                                          texCoordToColor ), mGlsl );
        
        mNormalsBatch = gl::Batch::create( geom::VertexNormalLines( extrudeSource, 3.0f ), gl::getStockShader( gl::ShaderDef().color() ) );
    }
}

void SacredGeometry1App::resize()
{
    mCam.setPerspective( 60.f, getWindowAspectRatio(), 1.0f, 1000.0f );
    gl::setMatrices( mCam );
}



void SacredGeometry1App::update()
{

}

    void SacredGeometry1App::draw()
    {
        //clear the screen
        gl::clear( Color( 0, 0, 0 ) );
        
        
        gl::pushMatrices();
        mFlower.draw();
        gl::popMatrices();
        
    }

CINDER_APP_NATIVE( SacredGeometry1App, RendererGl )
