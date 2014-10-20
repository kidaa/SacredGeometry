#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SacredGeometry1App : public AppNative {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void SacredGeometry1App::setup()
{
}

void SacredGeometry1App::mouseDown( MouseEvent event )
{
}

void SacredGeometry1App::update()
{
}

void SacredGeometry1App::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( SacredGeometry1App, RendererGl )
