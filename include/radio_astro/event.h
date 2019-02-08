/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_RADIO_ASTRO_EVENT_H
#define INCLUDED_RADIO_ASTRO_EVENT_H

#include <radio_astro/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace radio_astro {

    /*!
     * \brief  event detection: fill a circular buffer with complex samples and
     * search for peaks nsigma above the RMS of the data stream
     * input:
     * complex vector of I/Q samples
     * parameters
     * 1. Vector length
     * 2. Number of sigma to declare an event
     * 3. Bandwidth used to unwind the time of the event in circular buffer
     * 4. Estimated time it takes for sample to go from input of horn to block
     * 5. Mode: 1: Monitor, just pass input data,
     *          2: Detect events and repeatedly output the last event
     * output:
     * 1: Vector of complex I/Q samples
     * Event is tagged with three floating point values:
     * 1. Modified Julian Date of Event
     * 2. Peak intensity
     * 3. RMS of data stream near event
     * Glen Langston - 2019 January 27
     * \ingroup radio_astro
     *
     */
    class RADIO_ASTRO_API event : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<event> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of radio_astro::event.
       *
       * To avoid accidental use of raw pointers, radio_astro::event's
       * constructor is in a private implementation
       * class. radio_astro::event::make is the public interface for
       * creating new instances.
       */
      static sptr make(int vlen, float n_sigma, float bw_hz, float dt, int mode);
    };

  } // namespace radio_astro
} // namespace gr

#endif /* INCLUDED_RADIO_ASTRO_EVENT_H */

