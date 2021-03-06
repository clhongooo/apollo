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

#include "modules/planning/common/speed_profile_generator.h"

#include "gtest/gtest.h"

#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

class SpeedProfileGeneratorTest : public ::testing::Test {
 public:
  virtual void SetUp() {}

 protected:
  SpeedProfileGenerator spg_;
};

TEST_F(SpeedProfileGeneratorTest, GenerateFallbackSpeedProfile) {
  ReferenceLineInfo reference_line_info;
  auto speed_data = spg_.GenerateFallbackSpeedProfile(reference_line_info);
  EXPECT_FALSE(speed_data.Empty());

  common::VehicleState vehicle_state;
  common::TrajectoryPoint adc_planning_point;
  ReferenceLine reference_line;
  hdmap::RouteSegments segments;
  adc_planning_point.set_v(FLAGS_polynomial_speed_fallback_velocity + 0.1);
  ReferenceLineInfo reference_line_info2(vehicle_state, adc_planning_point,
                                         reference_line, segments);
  auto speed_data2 = spg_.GenerateFallbackSpeedProfile(reference_line_info);
  EXPECT_FALSE(speed_data2.Empty());
}

}  // namespace planning
}  // namespace apollo
