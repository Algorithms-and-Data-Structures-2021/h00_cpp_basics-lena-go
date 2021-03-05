#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int* lhs, int* rhs) {
    if (lhs && rhs) {
        int tmp = *lhs;
        *lhs = *rhs;
        *rhs = tmp;
    }
}

// Задание 2
int** allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if ((num_rows > 0) && (num_cols > 0)) {
        int** array_2d = new int* [num_rows];
        for (int row_index = 0; row_index < num_rows; ++row_index) {
            array_2d[row_index] = new int[num_cols] {};
        }
        for (int row_index = 0; row_index < num_rows; row_index++) {
            for (int column_index = 0; column_index < num_cols; column_index++) {
                array_2d[row_index][column_index] = init_value;
            }
        }
        return array_2d;
    }
    return nullptr;
}

// Задание 3
bool copy_2d_array(int** arr_2d_source, int** arr_2d_target, int num_rows, int num_cols) {
    if ((!arr_2d_source) || (!arr_2d_target) || num_rows <= 0 || num_cols <= 0) {
        return false;
    }
    for (int row_index = 0; row_index < num_rows; row_index++) {
        for (int column_index = 0; column_index < num_cols; column_index++) {
            arr_2d_target[row_index][column_index] = arr_2d_source[row_index][column_index];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int>& arr) {
    if (arr.size()) {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
}

// Задание 5
void reverse_1d_array(int* arr_begin, int* arr_end) {
    if (arr_begin && arr_end) {
        while (arr_begin < arr_end) {
            swap_args(arr_begin, arr_end);
            arr_begin++; arr_end--;
        }
    }
}

// Задание 6
int* find_max_element(int* arr, int size) {
    if (!arr || size <= 0) {
        return nullptr;
    }
    int* max_elem = &arr[0];
    int i = 1;
    while (i < size) {
        if (arr[i] > *max_elem) {
            max_elem = &arr[i];
        }
        i++;
    }
    return max_elem;
}

// Задание 7
vector<int> find_odd_numbers(vector<int>& arr) {
    if (arr.size() > 0) {
        vector<int> odd_numbers_array;
        for (auto& elem : arr) {
            if (abs(elem) % 2 == 1) {
                odd_numbers_array.push_back(elem);
            }
        }
        return odd_numbers_array;
    }
    return {};
}

// Задание 8
vector<int> find_common_elements(vector<int>& arr_a, vector<int>& arr_b) {
    if (arr_a.size() > 0 && arr_b.size() > 0) {
        vector<int> common_elements_array;
        for (auto& elem_b : arr_b) {
            for (auto& elem_a : arr_a) {
                if (elem_b == elem_a) {
                    bool elem_exists = false;
                    if (common_elements_array.size() > 0) {
                        for (auto& elem : common_elements_array) {
                            if (!elem_exists && elem_b == elem) {
                                elem_exists = true;
                            }
                        }
                    }
                    if (!elem_exists) {
                        common_elements_array.push_back(elem_b);
                    }
                }
            }
        }
        return common_elements_array;
    }
    return {};
}