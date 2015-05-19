
#include "roomy.hxx"

#include "../avtk/theme.hxx"

#include <sstream>

#define WIDTH  120
#define HEIGHT  60

RoomyUI::RoomyUI(PuglNativeWindow parent) :
  Avtk::UI( WIDTH, HEIGHT, parent, "Roomy : ArtyFX : OpenAV" )
{
  Avtk::Widget* w = 0;
  dial1 = new Avtk::Dial( this, 10, 10, WIDTH/2-20, HEIGHT-20, "Dial 1" );
  
  dial2 = new Avtk::Dial( this, WIDTH/2+10, 10, WIDTH/2-20, HEIGHT-20, "Dial 2" );
  dial2->rClickMode( Widget::RCLICK_NONE );
  
  Avtk::Dial* dial3 = new Avtk::Dial( this, WIDTH/3+00, 10, WIDTH/2-20, HEIGHT-20, "Dial 3" );
  dial3->rClickMode( Widget::RCLICK_NONE );
}
