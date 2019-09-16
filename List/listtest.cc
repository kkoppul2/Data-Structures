#include <gtest/gtest.h>
#include "SinglyLinkedList.h"

namespace {

class ListTest : public ::testing::Test {
 protected:
  void SetUp() override {
    list1_.InsertFront(1);
  }

  SinglyLinkedList<int> list1_;
  SinglyLinkedList<int> list2_;
};
}  // namespace

TEST(SinglyLinkedListTest, Initialization) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char  **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
