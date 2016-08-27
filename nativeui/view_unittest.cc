// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#include "nativeui/init.h"
#include "nativeui/label.h"
#include "nativeui/window.h"
#include "testing/gtest/include/gtest/gtest.h"

class ViewTest : public testing::Test {
 protected:
  void SetUp() override {
    nu::Initialize();
    view_ = new nu::Label;
  }

  scoped_refptr<nu::View> view_;
};

TEST_F(ViewTest, Bounds) {
  nu::Rect bounds(100, 100, 200, 200);
  view_->SetBounds(bounds);
  EXPECT_EQ(view_->GetBounds(), bounds);
  EXPECT_EQ(view_->GetWindowPixelOrigin(), nu::Point(100, 100));
}

TEST_F(ViewTest, AddToChildView) {
  scoped_refptr<nu::Window> window(new nu::Window(nu::Window::Options()));
  window->GetContentView()->AddChildView(view_.get());

  nu::Rect bounds(100, 100, 200, 200);
  window->SetContentBounds(bounds);
  EXPECT_EQ(view_->GetBounds(), nu::Rect(0, 0, 200, 200));
  EXPECT_EQ(view_->GetWindowPixelOrigin(), nu::Point(0, 0));
}