#ifndef TST_BUBLE_H
#define TST_BUBLE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <math.h>
#include "../../sorting.h"

using namespace testing;
using namespace sorted;

std::vector<int> data(1000);

void Genereate(std::vector<int> &data) {
  for (auto &unit : data) {
    unit = std::rand();
  }
}

TEST(sorted, buble) {
  Genereate(data);
  EXPECT_EQ(1, 1);
}

TEST(sorted, buble_0) {
  std::vector<int> data_(data);
  Bubble(data_);
  EXPECT_EQ(1, 1);
}

// TEST(sorted, buble_1) {
//  std::vector<int> data_(data);
//  std::sort(data_.begin(), data_.end());
//  EXPECT_EQ(1, 1);
//}

// TEST(sorted, buble_2) {
//  std::vector<int> data_(data);
//  int *data__ = data_.data();
//  Bubble_v1(&data__[0], &data__[data_.size()]);
//  EXPECT_EQ(1, 1);
//}

#endif  // TST_BUBLE_H
