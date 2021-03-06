/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
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

#ifndef INCLUDED_LPWAN_DSSS_SNR_ESTIMATOR_IMPL_H
#define INCLUDED_LPWAN_DSSS_SNR_ESTIMATOR_IMPL_H

#include <lpwan/dsss_snr_estimator.h>
namespace gr {
  namespace lpwan {

    class dsss_snr_estimator_impl : public dsss_snr_estimator
    {
     private:
        int d_codebits_len;
        int d_sf;

        std::deque<std::vector<float>> d_soft_bits;
        std::deque<std::vector<uint8_t >> d_hard_bits;
        std::deque<std::vector<uint8_t >> d_hard_bits_checked;
        std::deque<std::vector<uint8_t >> d_hard_bits_unchecked;

        void in_hard_fec_enc(pmt::pmt_t msg);
        void in_hard(pmt::pmt_t msg);
        void in_hard_fec_dec(pmt::pmt_t msg);
        void in_soft(pmt::pmt_t msg);

        void calc_snr();

     public:
      dsss_snr_estimator_impl(int psdu_size, int sf);
      ~dsss_snr_estimator_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace lpwan
} // namespace gr

#endif /* INCLUDED_LPWAN_DSSS_SNR_ESTIMATOR_IMPL_H */

