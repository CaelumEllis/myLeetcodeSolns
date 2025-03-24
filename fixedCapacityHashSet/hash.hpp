#ifndef HASH_HPP_
#define HASH_HPP_

#include <list>
#include <algorithm>

template <std::size_t N>
class Hash {
  std::list<int> buckets[N] {};
  std::size_t numElements {};

 public:
  void insert(int key) {
    //to return the correct hash bucket to put the data into (I think correct terminology)
    std::size_t index = key % N;
    //Now that the correct bucked of the 'hash' is identified, enter an element into it
    // auto& gives us a reference to the specific bucked to reduce processing to repeatedly find the bucket
    auto& bucket = buckets[index];
    //ensuring no duplication
    if(std::find(bucket.begin(), bucket.end(), key) == bucket.end()){
    //if the element/key does not yet exist in the hash bucket
    buckets[index].push_back(key);
    //adjust element cnt
    ++numElements;
    }
  }

  void erase(int key) {
    std::size_t index = key % N;
    auto& bucket = buckets[index];
    //returns location of key
    auto target = std::find(bucket.begin(), bucket.end(), key);
    //ensure erasure isn't attemted if the element is not in the hash bucket
    if(target != bucket.end()) {
      bucket.erase(target);
      --numElements;
    }
  }

  bool contains(int key) {
    std::size_t index = key % N;
    auto& bucket = buckets[index];
    //returns true if element is found in the hash bucket
    return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
  }

  std::size_t size() {
    return numElements;
  }
};

#endif      // HASH_HPP_
