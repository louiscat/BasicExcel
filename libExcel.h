//
// Created by io on 2023/4/9.
//

#ifndef TRANSFORM_LIBEXCEL_H
#define TRANSFORM_LIBEXCEL_H

#include "BasicExcel.hpp"
#include <string>
#include <memory>
#include <windows.h>
#include <codecvt>
#include <vector>
#include <algorithm>

#ifdef __cplusplus
extern "C" {
#endif

    using namespace YExcel;
    using namespace std;

    unique_ptr<wchar_t[]> String2Wchar(string str);
    string Wchar2String(const wchar_t* wcharptr);
    string Char2String(const char* charptr);
    string GetValue(BasicExcelCell* cell);
    vector<vector<string>> Excel2Vector(BasicExcelWorksheet* sheet);
    BasicExcelWorksheet* Vector2Excel(BasicExcelWorksheet* sheet, const vector<vector<string>>& data);
    void ExcelSort(vector<vector<string>>& arr, int col);

#ifdef __cplusplus
}
#endif
#endif //TRANSFORM_LIBEXCEL_H
