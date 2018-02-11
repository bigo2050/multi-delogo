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
#ifndef MDL_FRAME_VIEW_H
#define MDL_FRAME_VIEW_H

#include <gtkmm.h>
#include <goocanvasmm.h>


namespace mdl {
  class SelectionRect;

  class FrameView : public Gtk::ScrolledWindow
  {
  public:
    FrameView(int width, int height);

    void set_image(Glib::RefPtr<Gdk::Pixbuf> pixbuf);

  private:
    Goocanvas::Canvas canvas_;
    Glib::RefPtr<Goocanvas::Image> image_;
    Glib::RefPtr<SelectionRect> rect_;
  };


  class SelectionRect : public Goocanvas::Rect
  {
  protected:
    SelectionRect(gdouble x, gdouble y, gdouble width, gdouble height);

  public:
    static Glib::RefPtr<SelectionRect> create(gdouble x=0.0, gdouble y=0.0, gdouble width=0.0, gdouble height=0.0);

  private:
    bool on_button_press(const Glib::RefPtr<Goocanvas::Item>& item, GdkEventButton* event);
    bool on_button_release(const Glib::RefPtr<Goocanvas::Item>& item, GdkEventButton* event);
    bool on_motion_notify(const Glib::RefPtr<Goocanvas::Item>& item, GdkEventMotion* event);

  };
}

#endif // MDL_FRAME_VIEW_H
