# 2.0.0
- add "libExcel.cpp","libExcel.h"
- add function
unique_ptr<wchar_t[]> String2Wchar(string str);  支持写入中文
string Wchar2String(const wchar_t* wcharptr);  
string Char2String(const char* charptr);  
string GetValue(BasicExcelCell* cell);  支持读取中文
vector<vector<string>> Excel2Vector(BasicExcelWorksheet* sheet);  
BasicExcelWorksheet* Vector2Excel(BasicExcelWorksheet* sheet, const vector<vector<string>>& data);  
void ExcelSort(vector<vector<string>>& arr, int col);
- update(change const char* to string)，支持中文路径
bool BasicExcel::Load(string xlsfilename);
bool BasicExcel::SaveAs(string xlsfilename);



# 1.0.1
- add "#include \<cstring\>" to BasicExcel.hpp
- build Basic Excel


# 1.0.0
add BasicExcel souce files