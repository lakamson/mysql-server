/*
   Copyright (c) 2024, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef CS_TIME_BASED_METRIC_H
#define CS_TIME_BASED_METRIC_H

#include <cstdint>  // int64_t

/// @brief Abstract class for time based metrics implementations
class Time_based_metric_interface {
 public:
  virtual ~Time_based_metric_interface() = default;

  /// @brief Resets the counter and summed time to 0
  virtual void reset() = 0;

  /// @brief Starts counting time we are waiting on something
  virtual void start_timer() = 0;

  /// @brief Stops the timer for the wait.
  ///        Requires start_timer to be called first
  virtual void stop_timer() = 0;

  /// @brief Returns the total time waited across all executions of the
  /// start/stop methods, minus the absolute start time of the last one in case
  /// it has not ended.
  /// @return The total time waited, in nanoseconds.
  virtual int64_t get_sum_time_elapsed() const = 0;

  /// @brief Increments the waiting counter
  virtual void increment_counter() = 0;

  /// @brief Returns the number of times we waited on give spot
  /// @return the number of times waited
  virtual int64_t get_count() const = 0;
};

#endif /* CS_TIME_BASED_METRIC_H */
