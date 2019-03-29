/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#pragma once

#include <algorithm>
#include <limits>
#include <string>

#include "modules/planning/tasks/task.h"
#include "ad_rss/core/RssCheck.hpp"
#include "TestSupport.hpp"

namespace apollo {
namespace planning {

class RssDecider : public Task {
 public:
  explicit RssDecider(const TaskConfig &config);

  apollo::common::Status Execute(
      Frame *frame, ReferenceLineInfo *reference_line_info) override;

 private:
  apollo::common::Status Process(Frame *frame,
                                 ReferenceLineInfo *reference_line_info);
  ad_rss::core::RssCheck rssCheck;

  void rss_config_default_dynamics(::ad_rss::world::Dynamics *dynamics);
  void rss_create_ego_object(::ad_rss::world::Object *ego,
      double vel_lon, double vel_lat);
  void rss_create_other_object(::ad_rss::world::Object *other,
      double vel_lon, double vel_lat);
};

}  // namespace planning
}  // namespace apollo
