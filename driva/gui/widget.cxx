// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "widget.h"

void DrivaWidget::cb_headerImage_i(Avtk::Image*, void*) {
  //system("xdg-open http://www.openavproductions.com/artyfx#ducka");
}
void DrivaWidget::cb_headerImage(Avtk::Image* o, void* v) {
  ((DrivaWidget*)(o->parent()->user_data()))->cb_headerImage_i(o,v);
}

void DrivaWidget::cb_graph_i(Avtk::Drive* o, void*) {
  float tmp = o->value();
distortion->value( tmp );
writePort(DRIVA_AMOUNT, tmp);

//volume->value( o->getVolume() );

float a = o->getActive();
//writePort(BITTA_ACTIVE, a);
//printf("active %f\n", a );
}
void DrivaWidget::cb_graph(Avtk::Drive* o, void* v) {
  ((DrivaWidget*)(o->parent()->user_data()))->cb_graph_i(o,v);
}

void DrivaWidget::cb_distortion_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->value( tmp );
graph->drive( tmp );
writePort(DRIVA_AMOUNT, tmp);
//printf("%f\n",tmp);
}
void DrivaWidget::cb_distortion(Avtk::Dial* o, void* v) {
  ((DrivaWidget*)(o->parent()->user_data()))->cb_distortion_i(o,v);
}

void DrivaWidget::cb_tone_i(Fl_Choice* o, void*) {
  float tmp = o->value();
graph->drive( tmp );
writePort(DRIVA_TONE, tmp);
printf("tone selector %f\n",tmp);
}
void DrivaWidget::cb_tone(Fl_Choice* o, void* v) {
  ((DrivaWidget*)(o->parent()->user_data()))->cb_tone_i(o,v);
}

/**
   if the type of filter changes, this function will highlight the right button
*/
void DrivaWidget::update_button(int button) {
}

DrivaWidget::DrivaWidget() {
  { Fl_Double_Window* o = window = new Fl_Double_Window(160, 220);
    window->user_data((void*)(this));
    { headerImage = new Avtk::Image(0, 0, 160, 29, "header.png");
      headerImage->box(FL_NO_BOX);
      headerImage->color(FL_BACKGROUND_COLOR);
      headerImage->selection_color(FL_BACKGROUND_COLOR);
      headerImage->labeltype(FL_NORMAL_LABEL);
      headerImage->labelfont(0);
      headerImage->labelsize(14);
      headerImage->labelcolor((Fl_Color)20);
      headerImage->callback((Fl_Callback*)cb_headerImage);
      headerImage->align(Fl_Align(FL_ALIGN_CENTER));
      headerImage->when(FL_WHEN_RELEASE_ALWAYS);
      headerImage->setPixbuf(header.pixel_data,4);
    } // Avtk::Image* headerImage
    { graph = new Avtk::Drive(5, 36, 150, 126, "graph");
      graph->box(FL_UP_BOX);
      graph->color((Fl_Color)179);
      graph->selection_color(FL_INACTIVE_COLOR);
      graph->labeltype(FL_NO_LABEL);
      graph->labelfont(0);
      graph->labelsize(14);
      graph->labelcolor(FL_FOREGROUND_COLOR);
      graph->callback((Fl_Callback*)cb_graph);
      graph->align(Fl_Align(FL_ALIGN_BOTTOM));
      graph->when(FL_WHEN_CHANGED);
    } // Avtk::Drive* graph
    { distortion = new Avtk::Dial(103, 169, 45, 35, "Distortion");
      distortion->box(FL_NO_BOX);
      distortion->color((Fl_Color)90);
      distortion->selection_color(FL_INACTIVE_COLOR);
      distortion->labeltype(FL_NORMAL_LABEL);
      distortion->labelfont(0);
      distortion->labelsize(10);
      distortion->labelcolor(FL_FOREGROUND_COLOR);
      distortion->callback((Fl_Callback*)cb_distortion);
      distortion->align(Fl_Align(FL_ALIGN_BOTTOM));
      distortion->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* distortion
    { tone = new Fl_Choice(12, 189, 80, 25, "Tone");
      tone->down_box(FL_BORDER_BOX);
      tone->callback((Fl_Callback*)cb_tone);
      tone->align(Fl_Align(FL_ALIGN_TOP));
      tone->when(FL_WHEN_CHANGED);
      tone->add("Odie"); tone->add("Grunge"); tone->add("Distort"); tone->add("Ratty"); tone->add("Classic"); tone->add("Morbid"); tone->add("Metal");
      tone->value( 0 );
    } // Fl_Choice* tone
    window->color( fl_rgb_color( 17, 17, 17) );
    close_cb( o, 0 );
    window->end();
  } // Fl_Double_Window* window
}

void DrivaWidget::idle() {
  Fl::check();
  Fl::flush();
}

int DrivaWidget::getWidth() {
  return window->w();
}

int DrivaWidget::getHeight() {
  return window->h();
}

void DrivaWidget::writePort(int port, float& value) {
  //cout << "port " << port << " value " << value << endl;
  write_function(controller, port, sizeof(float), 0, &value);
}

void DrivaWidget::close_cb(Fl_Widget* o, void*) {
  if ((Fl::event() == FL_KEYDOWN || Fl::event() == FL_SHORTCUT) && Fl::event_key() == FL_Escape)
    {
      return; // ignore ESC
    }
    else
    {
      o->hide();
    }
}
