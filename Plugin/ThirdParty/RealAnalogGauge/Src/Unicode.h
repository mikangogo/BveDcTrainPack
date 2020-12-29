#ifndef _UNICODE_H_
#define _UNICODE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <tchar.h>
#include <string>
#include <locale.h>

// 文字列はUnicode、マルチバイト文字に対応するためにTCHAR型がお勧めです
// _T("文字列")マクロで囲ってやるとTCHAR文字列として扱えます

// 標準出力 _tprintf ,printf ,wprintf
// バッファに整形出力 _stprintf ,sprintf ,swprintf
// 文字列比較 _tcscmp ,strcmp ,lstrcmp

// 標準で欲しいレベルなので
// std名前空間として扱う
_STD_BEGIN

// tstring型を定義
typedef std::basic_string<TCHAR> tstring;

// tstream型の定義
typedef std::basic_ostream<TCHAR> tostream; // 標準出力ストリーム
typedef std::basic_istream<TCHAR> tistream; // 標準入力ストリーム
typedef std::basic_ostringstream<TCHAR> tostringstream; // 文字列出力ストリーム（整形格納用バッファ）
typedef std::basic_istringstream<TCHAR> tistringstream; // 文字列入力ストリーム（整形取得用バッファ）
typedef std::basic_stringstream<TCHAR> tstringstream; // 文字列入出力ストリーム（整形取得用バッファ）
typedef std::basic_ifstream<TCHAR> tifstream; // ファイル入力ストリーム
typedef std::basic_ofstream<TCHAR> tofstream; // ファイル出力ストリーム
typedef std::basic_fstream<TCHAR> tfstream; // ファイルストリーム

// 標準出力の切り替えマクロ
#ifdef UNICODE
#define tcin wcin // 入力
#define tcout wcout // 出力
#define tcerr wcerr // エラー
#define tclog wclog // ログ
#define tsetlocale _wsetlocale // ロケール設定
#define _tsplitpath_s _wsplitpath_s // パス分割

#else
#define tcin cin // 入力
#define tcout cout // 出力
#define tcerr cerr // エラー
#define tclog clog // ログ
#define tsetlocale setlocale // ロケール設定
#define _tsplitpath_s _splitpath_ // パス分割
#endif

_STD_END

#endif // _UNICODE_H_