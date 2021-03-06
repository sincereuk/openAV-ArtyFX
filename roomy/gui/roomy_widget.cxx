// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "roomy_widget.h"

void RoomyUI::cb_headerImage_i(Avtk::Image*, void*) {
  //system("xdg-open http://www.openavproductions.com/artyfx#ducka");
}
void RoomyUI::cb_headerImage(Avtk::Image* o, void* v) {
  ((RoomyUI*)(o->parent()->user_data()))->cb_headerImage_i(o,v);
}

void RoomyUI::cb_graph_i(Avtk::Reverb* o, void*) {
  //cutoff = o->value();
//float g = o->getGain();
//gainDial->value( g );
//freq->value( cutoff ); // update dial
//writePort(CUTOFF_FREQ, cutoff);
//writePort(CUTOFF_GAIN, g);
}
void RoomyUI::cb_graph(Avtk::Reverb* o, void* v) {
  ((RoomyUI*)(o->parent()->user_data()))->cb_graph_i(o,v);
}

void RoomyUI::cb_time_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->size( tmp );
writePort( int(ROOMY_TIME), tmp );
}
void RoomyUI::cb_time(Avtk::Dial* o, void* v) {
  ((RoomyUI*)(o->parent()->user_data()))->cb_time_i(o,v);
}

void RoomyUI::cb_damping_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->damping( tmp );
writePort( int(ROOMY_DAMPING), tmp );
}
void RoomyUI::cb_damping(Avtk::Dial* o, void* v) {
  ((RoomyUI*)(o->parent()->user_data()))->cb_damping_i(o,v);
}

void RoomyUI::cb_dryWet_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->wet( tmp );
writePort( int(ROOMY_DRY_WET),tmp );
}
void RoomyUI::cb_dryWet(Avtk::Dial* o, void* v) {
  ((RoomyUI*)(o->parent()->user_data()))->cb_dryWet_i(o,v);
}

RoomyUI::RoomyUI() {
  { roomy_window = new Fl_Double_Window(160, 220, "Roomy");
    roomy_window->user_data((void*)(this));
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
    { graph = new Avtk::Reverb(5, 36, 150, 126, "graph");
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
    } // Avtk::Reverb* graph
    { time = new Avtk::Dial(10, 169, 37, 37, "Time");
      time->box(FL_NO_BOX);
      time->color((Fl_Color)90);
      time->selection_color(FL_INACTIVE_COLOR);
      time->labeltype(FL_NORMAL_LABEL);
      time->labelfont(0);
      time->labelsize(10);
      time->labelcolor(FL_FOREGROUND_COLOR);
      time->callback((Fl_Callback*)cb_time);
      time->align(Fl_Align(FL_ALIGN_BOTTOM));
      time->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* time
    { damping = new Avtk::Dial(62, 169, 37, 37, "Damping");
      damping->box(FL_NO_BOX);
      damping->color((Fl_Color)90);
      damping->selection_color(FL_INACTIVE_COLOR);
      damping->labeltype(FL_NORMAL_LABEL);
      damping->labelfont(0);
      damping->labelsize(10);
      damping->labelcolor(FL_FOREGROUND_COLOR);
      damping->callback((Fl_Callback*)cb_damping);
      damping->align(Fl_Align(FL_ALIGN_BOTTOM));
      damping->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* damping
    { dryWet = new Avtk::Dial(113, 168, 37, 37, "Dry / Wet");
      dryWet->box(FL_NO_BOX);
      dryWet->color((Fl_Color)90);
      dryWet->selection_color(FL_INACTIVE_COLOR);
      dryWet->labeltype(FL_NORMAL_LABEL);
      dryWet->labelfont(0);
      dryWet->labelsize(10);
      dryWet->labelcolor(FL_FOREGROUND_COLOR);
      dryWet->callback((Fl_Callback*)cb_dryWet);
      dryWet->align(Fl_Align(FL_ALIGN_BOTTOM));
      dryWet->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* dryWet
    roomy_window->color( fl_rgb_color( 17, 17, 17) );
    roomy_window->end();
  } // Fl_Double_Window* roomy_window
}

void RoomyUI::idle() {
  Fl::check();
  Fl::flush();
}

int RoomyUI::getWidth() {
  return roomy_window->w();
}

int RoomyUI::getHeight() {
  return roomy_window->h();
}

void RoomyUI::writePort(int port, float& value) {
  //cout << "port " << port << " value " << value << endl;
  write_function(controller, port, sizeof(float), 0, &value);
}
