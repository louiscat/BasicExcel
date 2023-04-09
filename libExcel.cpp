//
// Created by io on 2023/4/9.
//
#include "libExcel.h"
#include "BasicExcel.hpp"
#include <string>
#include <memory>
#include <windows.h>
#include <codecvt>
#include <vector>
#include <algorithm>

using namespace YExcel;
using namespace std;

//string转wchar_t*,需配合.get()使用
unique_ptr<wchar_t[]> String2Wchar(string str)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    unique_ptr<wchar_t[]> wstr(new wchar_t[len]);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr.get(), len);
    return wstr;
}
//wchar_t*转string
string Wchar2String(const wchar_t* wcharptr)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wcharptr);
}
//char*转string
string Char2String(const char* charptr)
{
    string result(charptr);
    return result;
}

string GetValue(BasicExcelCell* cell)
{
    switch (cell->Type())
    {
        case 0:
            return "";
            break;
        case 1:
            return "INT";
            break;
        case 2:
            return "DOUBLE";
            break;
        case 3:
            return cell->GetString();
            break;
        case 4:
            return Wchar2String(cell->GetWString());
            break;
        default:
            return "UNKNOWN";
            break;
    }
}

vector<vector<string>> Excel2Vector(BasicExcelWorksheet* sheet) {
    int rows = sheet->GetTotalRows();
    int cols = sheet->GetTotalCols();

    vector<vector<string>> data(rows, vector<string>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            BasicExcelCell* cell = sheet->Cell(i, j);
            data[i][j] = GetValue(cell);
        }
    }
    return data;
}
BasicExcelWorksheet* Vector2Excel(BasicExcelWorksheet* sheet, const vector<vector<string>>& data) {
    int rows = data.size();
    int cols = data[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sheet->Cell(i, j)->SetWString(String2Wchar(data[i][j]).get());
        }
    }
    return sheet;
}

void ExcelSort(vector<vector<string>>& arr, int col) {
    sort(arr.begin()+1, arr.end(), [col](const vector<string>& a, const vector<string>& b) {
        if (a[col] == "") return false;
        if (b[col] == "") return true;
        return a[col] < b[col];
    });
}
