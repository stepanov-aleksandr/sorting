#ifndef SORTING_H
#define SORTING_H

#include <iterator>
#include <vector>

namespace sorted {
/**
 * @brief сортировка пузырьком
 * @param[in] data входной массив
 */
bool Bubble(std::vector<int> data);
/**
 * @brief сортировка пузырьком 2
 * @param[in] data входной массив
 */
bool Bubble_v1(int *, int *);

/**
 * @brief шейкерная сортировка
 * @param[in] data входной массив
 */
void ShakerSort(std::vector<int> &data);

/**
 * @brief сортировка пузырьком
 * @param[in] итератор на начало массива
 * @param[in] итератор на конец массива
 */
void QuickSorted(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end, std::vector<int> &data);

  /**
 * @brief сортировка вставками
 * @param[in] data массив
 */
  void SortInsert(std::vector<int> &data)
  
}  // namespace sorted

#endif  // SORTING_H
