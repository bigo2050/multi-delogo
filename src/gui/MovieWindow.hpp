/*
 * Copyright (C) 2018 Werner Turing <werner.turing@protonmail.com>
 *
 * This file is part of multi-delogo.
 *
 * multi-delogo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * multi-delogo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with multi-delogo.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MDL_MOVIE_WINDOW_H
#define MDL_MOVIE_WINDOW_H

#include <gtkmm.h>

#include "common/FrameProvider.hpp"

#include "NumericEntry.hpp"
#include "FrameView.hpp"


namespace mdl {
  class MovieWindow : public Gtk::ApplicationWindow
  {
  public:
    MovieWindow(const Glib::RefPtr<FrameProvider>& frame_provider);

  private:
    Glib::RefPtr<FrameProvider> frame_provider_;
    int number_of_frames_;
    int frame_number_;

    FrameView frame_view_;

    NumericEntry txt_frame_number_;
    NumericEntry txt_jump_size_;

    int zoom_;
    Gtk::Label lbl_zoom_;
    Gtk::Button btn_zoom_out_;
    Gtk::Button btn_zoom_in_;


    Gtk::Box* create_navigation_box();
    Gtk::Box* create_zoom_box();

    void change_displayed_frame(int new_frame_number);

    void on_single_step_frame(int direction);
    void on_jump_step_frame(int direction);
    void on_frame_number_activate();
    bool on_frame_number_input(GdkEventFocus*);
    bool on_key_press(GdkEventKey* key_event);
  };
}

#endif // MDL_MOVIE_WINDOW_H
