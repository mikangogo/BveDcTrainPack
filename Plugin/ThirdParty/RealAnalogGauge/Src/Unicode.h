#ifndef _UNICODE_H_
#define _UNICODE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <tchar.h>
#include <string>
#include <locale.h>

// �������Unicode�A�}���`�o�C�g�����ɑΉ����邽�߂�TCHAR�^�������߂ł�
// _T("������")�}�N���ň͂��Ă���TCHAR������Ƃ��Ĉ����܂�

// �W���o�� _tprintf ,printf ,wprintf
// �o�b�t�@�ɐ��`�o�� _stprintf ,sprintf ,swprintf
// �������r _tcscmp ,strcmp ,lstrcmp

// �W���ŗ~�������x���Ȃ̂�
// std���O��ԂƂ��Ĉ���
_STD_BEGIN

// tstring�^���`
typedef std::basic_string<TCHAR> tstring;

// tstream�^�̒�`
typedef std::basic_ostream<TCHAR> tostream; // �W���o�̓X�g���[��
typedef std::basic_istream<TCHAR> tistream; // �W�����̓X�g���[��
typedef std::basic_ostringstream<TCHAR> tostringstream; // ������o�̓X�g���[���i���`�i�[�p�o�b�t�@�j
typedef std::basic_istringstream<TCHAR> tistringstream; // ��������̓X�g���[���i���`�擾�p�o�b�t�@�j
typedef std::basic_stringstream<TCHAR> tstringstream; // ��������o�̓X�g���[���i���`�擾�p�o�b�t�@�j
typedef std::basic_ifstream<TCHAR> tifstream; // �t�@�C�����̓X�g���[��
typedef std::basic_ofstream<TCHAR> tofstream; // �t�@�C���o�̓X�g���[��
typedef std::basic_fstream<TCHAR> tfstream; // �t�@�C���X�g���[��

// �W���o�͂̐؂�ւ��}�N��
#ifdef UNICODE
#define tcin wcin // ����
#define tcout wcout // �o��
#define tcerr wcerr // �G���[
#define tclog wclog // ���O
#define tsetlocale _wsetlocale // ���P�[���ݒ�
#define _tsplitpath_s _wsplitpath_s // �p�X����

#else
#define tcin cin // ����
#define tcout cout // �o��
#define tcerr cerr // �G���[
#define tclog clog // ���O
#define tsetlocale setlocale // ���P�[���ݒ�
#define _tsplitpath_s _splitpath_ // �p�X����
#endif

_STD_END

#endif // _UNICODE_H_