#include <gtest/gtest.h>
#include "hash.hpp"

TEST(hashTest, insertOne) {
  const std::size_t size {5};
  Hash<size> h;
  const int key {53};
  h.insert(key);
  ASSERT_TRUE(h.contains(key));
  ASSERT_FALSE(h.contains(key + static_cast<int>(size)));
}

TEST(hashTest, insertOneNegative) {
  const std::size_t size {5};
  Hash<size> h;
  const int key {-38};
  h.insert(key);
  ASSERT_TRUE(h.contains(key));
  ASSERT_FALSE(h.contains(key + static_cast<int>(size)));
}

TEST(hashTest, insertAndSize) {
  const std::size_t size {5};
  Hash<size> h;
  const int key {53};
  h.insert(key);
  ASSERT_EQ(h.size(), 1u);
}

TEST(hashTest, insertMultiple) {
  const std::size_t size {13};
  Hash<size> h;
  const std::size_t N {10};
  for (std::size_t i = 0; i < N * size; i += size) {
    h.insert(i);
  }
  ASSERT_EQ(h.size(), N);
}

TEST(hashTest, insertAndEraseOne) {
  const std::size_t size {5};
  Hash<size> h;
  const int key {38};
  h.insert(key);
  ASSERT_TRUE(h.contains(key));
  h.erase(key);
  ASSERT_FALSE(h.contains(key));
}

TEST(hashTest, insertAndEraseMultiple) {
  const std::size_t size {13};
  Hash<size> h;
  std::size_t N {30};
  for (std::size_t i = 0; i < N; ++i) {
    h.insert(i);
  }
  ASSERT_EQ(h.size(), N);
  ASSERT_TRUE(h.contains(18));
  for (std::size_t i = 0; i < N + 1; ++i) {
    h.erase(i);
  }
  ASSERT_EQ(h.size(), 0u);
  ASSERT_FALSE(h.contains(1));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
