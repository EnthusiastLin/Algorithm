/**
 * @file insertion_sort.c
 * @author Shencheng Lin (deeplinshencheng@gmail.com)
 * @brief 插入排序算法的实现。
 * @version 2.0
 * @date 2024-03-27
 *
 * 插入排序为稳定排序:
 * - 平均、最坏时间复杂度: O(n^2)
 * - 最好时间复杂度: O(n)
 * - 空间复杂度: O(1)
 *
 * @copyright Copyright (c) 2024 Shencheng Lin. All rights reserved.
 * This code is for personal use only and may not be redistributed without
 * permission.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

#define SWAP(arr, i, j) \
  do {                  \
    int tmp = arr[i];   \
    arr[i] = arr[j];    \
    arr[j] = tmp;       \
  } while (0)

/**
 * @brief 释放内存。
 * @param arr 要释放的数组指针。
 */
void Destroy(int* arr) { free(arr); }

/**
 * @brief 初始化数组。
 * @param size 数组大小。
 * @param min 数组元素的最小值。
 * @param max 数组元素的最大值。
 * @return 初始化后的数组指针。
 */
int* Init(int size, int min, int max) {
  int* arr = (int*)malloc(size * sizeof(int));
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % (max - min + 1) + min;
  }
  return arr;
}

/**
 * @brief 打印数组。
 * @param arr 要打印的数组指针。
 * @param size 数组大小。
 */
void Print(const int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/**
 * @brief 插入排序。
 * @param arr 要排序的数组指针。
 * @param size 数组大小。
 */
void InsertionSort(int* arr, int size) {
  for (int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

/**
 * @brief 主函数。
 * @return 返回值为 0，表示程序正常结束。
 */
int main() {
  int* arr = Init(MAX_SIZE, 1, MAX_SIZE);
  Print(arr, MAX_SIZE);
  InsertionSort(arr, MAX_SIZE);
  Print(arr, MAX_SIZE);
  Destroy(arr);
  return 0;
}