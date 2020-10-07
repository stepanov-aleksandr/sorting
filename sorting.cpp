#include "sorting.h"

namespace sorted {

bool Bubble(std::vector<int> data) {
  while (true) {
    bool flag = false;
    for (auto itr = data.begin(); itr != data.end(); itr++) {
      if (itr != data.end()) {
        auto cur = *itr;
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = cur;
          flag = true;
        }
      }
    }
    if (flag != true) return true;
  }
  return false;
}

bool Bubble_v1(int *begin, int *end) {
  while (true) {
    bool flag = false;
    for (auto itr = begin; itr != end + 1; itr++) {
      if (itr != end + 1) {
        auto cur = *itr;
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = cur;
          flag = true;
        }
      }
    }
    if (flag != true) return true;
  }
  return false;
}

void ShakerSort(std::vector<int> &data) {
  auto end_itr = data.end();
  auto cur_itr = data.end();
  bool flag = false;

  while (true) {
    flag = false;
    end_itr = cur_itr;
    for (auto itr = data.begin(); itr != end_itr; itr++) {
      auto buffer = *itr;
      if (itr != end_itr) {
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = buffer;
          cur_itr = itr + 1;
          flag = true;
        }
      }
    }
    if (flag == false) return;
  }
}

  void QuickSorted(const std::vector<int>::iterator begin,
                 const std::vector<int>::iterator end, std::vector<int> &data) {
  std::vector<int>::iterator left_itr = begin + 1;
  std::vector<int>::iterator right_itr = end - 1;

  if (std::distance(begin, end) == 1) {
    if (*begin > *end) {
      std::swap(*begin, *end);
    }
    return;
  }

  while (left_itr < (right_itr - 1)) {
    while (*left_itr < *begin) {
      left_itr++;
    }
    while (*right_itr > *begin) {
      right_itr--;
    }
    if (*left_itr > *right_itr) {
      std::swap(*left_itr, *right_itr);
    }
  }

  std::swap(*left_itr, *begin);
  if (begin < right_itr) {
    QuickSorted(begin, left_itr, data);
  }
  if (end > left_itr) {
    QuickSorted(right_itr, end, data);
  }
}

  template <typename T>
void MergeSort(T array[], std::size_t size) noexcept {
  if (size > 1) {
    std::size_t const left_size = size / 2;
    std::size_t const right_size = size - left_size;

    MergeSort(&array[0], left_size);
    MergeSort(&array[left_size], right_size);

    std::size_t len_x = 0, len_y = left_size, x = 0;
    std::unique_ptr<T[]> buffer(new T[size]);

    while (len_x < left_size || len_y < size) {
      if (array[len_x] < array[len_y]) {
        buffer[x++] = std::move(array[len_x]);
        len_x++;
      } else {
        buffer[x++] = std::move(array[len_y]);
        len_y++;
      }

      if (len_x == left_size) {
        std::copy(std::make_move_iterator(&array[len_y]),
                  std::make_move_iterator(&array[size]), &buffer[x]);
        break;
      }
      if (len_y == size) {
        std::copy(std::make_move_iterator(&array[len_x]),
                  std::make_move_iterator(&array[left_size]), &buffer[x]);
        break;
      }
    }
    std::copy(std::make_move_iterator(&buffer[0]),
              std::make_move_iterator(&buffer[size]), array);
  }
}
  
  void SortInsert(std::vector<int> &data) {
  std::vector<int>::iterator stop = data.end() - 1;
  std::vector<int>::iterator max = data.begin();
  while (max != stop) {
    for (std::vector<int>::iterator itr = data.begin(); itr != stop; itr++) {
      if (*itr >= *max) {
        max = itr;
      }
    }
    std::swap(*stop--, *max);
  }
}
  
  void SortInsert_(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end, const std::vector<int> &data) {
  std::vector<int>::iterator stop = end - 1;
  std::vector<int>::iterator max = begin;
  if (max == stop) {
    return;
  }
  for (std::vector<int>::iterator itr = begin; itr != stop; itr++) {
    if (*itr >= *max) {
      max = itr;
    }
  }
  if (*max > *(stop - 1)) std::swap(*stop, *max);
  SortInsert_(begin, stop, data);
}

  
}  // namespace sorted
