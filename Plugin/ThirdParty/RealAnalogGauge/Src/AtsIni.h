//
// Generated on 2015/10/20 by inimoni 
//

/*
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Documentation
  Struct = Section name, Field = Key name.
  The function used is only a declaration, load(), and save().
  The constructor automatically reads initialization file [initGauge].
  Please rewrite [initGauge] in the source freely.
  It becomes Windows folder when there is not path. The relative path can be used.

Example
#include "SampleIni.h"
void CTestDlg::OnButton1()
{
    //initGauge = "./sample.ini";
    SampleIni data1;                   // Open ./sample.ini
    int v = data1.Sample.value;        // [Sample]-value Get
    data1.Sample.value = v+1;          // [Sample]-value Modify
    data1.save();                      // Save ./Sample.ini (Opened file)

    SampleIni data2("sample.ini");     // Open C:/WINDOWS/Sample.ini
    data2.load("./sample.ini");        // Open Specified file.
    data2.save();                      // Save Opened file (Making at not being)
}

Supplementation
  Reading and writing becomes the unit of the file.
  [initGauge] is the same as the argument of GetPrivateProfileString() of SDK.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*/

#ifndef ATSINI_H
#define ATSINI_H

#include <string>
using namespace std;

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#ifdef _UNICODE
	typedef std::wstring string_t;
#else
	typedef std::string string_t;
#endif

namespace inimoni{
    template<class T>
    static bool inirw(int is_read, string_t& fname, string_t sec, string_t key, T& val_t);
};

/**
    Ats.ini input output class.
*/
class AtsIni
{
public:                                                                 
                                                                        
    AtsIni(string_t fname=_T(""))                          
    {                                                                   
        initGauge = _T("./Ats.ini"); //Default file.    
        init();                                                         
        load(fname);                                                    
    }                                                                   
                                                                        
    /**                                                                 
        INI file is read.                                               
        @param fname Gauge                                           
        When there is not a file, It becomes initGauge.              
        When there is not a pass, It becomes Windows folder.            
    */                                                                  
    bool load(string_t fname=_T(""))                                  
    {                                                                   
        if(fname.empty()){                                              
            fname = initGauge;                                       
        }                                                               
        loadGauge = fname;                                           
        WIN32_FIND_DATA fd;                                             
        HANDLE h = ::FindFirstFile(fname.c_str(), &fd);                 
        if (h != INVALID_HANDLE_VALUE) {                                
            iniRW(fname,1);                                             
        }                                                               
        return (h != INVALID_HANDLE_VALUE);                             
    }                                                                   
                                                                        
    /**                                                                 
        It writes it in the INI file.                                   
        @param fname Gauge                                           
        When there is not a file, It becomes open file.                 
        When there is not a pass, It becomes Windows folder.            
    */                                                                  
    bool save(string_t fname=_T(""))                                  
    {                                                                   
        if(fname.empty()){                                              
            fname = loadGauge;                                       
        }                                                               
        iniRW(fname,0);                                                 
        return true;                                                    
    }                                                                   

public:                                                                 

    // SubjectKey
    struct _SubjectKey
    {
        string_t Subject;
    } SubjectKey;

    // FileName
    struct _FileName
    {
        string_t Gauge0;
        string_t Gauge1;
        string_t Gauge2;
        string_t Gauge3;
        string_t Gauge4;
        string_t Gauge5;
        string_t Gauge6;
        string_t Gauge7;
        string_t Gauge8;
        string_t Gauge9;
        string_t Gauge10;
        string_t Gauge11;
        string_t Gauge12;
        string_t Gauge13;
        string_t Gauge14;
        string_t Gauge15;
    } FileName;

    // PanelIndex
    struct _PanelIndex
    {
        int      Needle;
        int      Ellipse0;
        int      Ellipse1;
        int      Ellipse2;
        int      Ellipse3;
        int      Ellipse4;
        int      Ellipse5;
        int      Ellipse6;
        int      Ellipse7;
        int      Ellipse8;
        int      Ellipse9;
        int      Ellipse10;
        int      Ellipse11;
        int      Ellipse12;
        int      Ellipse13;
        int      Ellipse14;
        int      Ellipse15;
        int      Ellipse16;
        int      Ellipse17;
        int      Ellipse18;
        int      Ellipse19;
        int      Ellipse20;
        int      Ellipse21;
        int      Ellipse22;
        int      Ellipse23;
        int      Ellipse24;
        int      Ellipse25;
        int      Ellipse26;
        int      Ellipse27;
        int      Ellipse28;
        int      Ellipse29;
        int      Ellipse30;
        int      Ellipse31;
		int      Ellipse32;
		int      Ellipse33;
		int      Ellipse34;
		int      Ellipse35;
		int      Ellipse36;
		int      Ellipse37;
		int      Ellipse38;
		int      Ellipse39;
		int      Ellipse40;
		int      Ellipse41;
		int      Ellipse42;
		int      Ellipse43;
		int      Ellipse44;
		int      Ellipse45;
		int      Ellipse46;
		int      Ellipse47;
		int      Ellipse48;
		int      Ellipse49;
		int      Ellipse50;
		int      Ellipse51;
		int      Ellipse52;
		int      Ellipse53;
		int      Ellipse54;
		int      Ellipse55;
		int      Ellipse56;
		int      Ellipse57;
		int      Ellipse58;
		int      Ellipse59;
		int      Ellipse60;
		int      Ellipse61;
		int      Ellipse62;
		int      Ellipse63;
    } PanelIndex;

    // Vibration
    struct _Vibration
    {
        double   Period;
        double   Amplitude;
        double   Threshold;
    } Vibration;

    // Damping
    struct _Damping
    {
        double   NaturalFreq;
        double   DampingRatio;
    } Damping;

    // Ellipse
    struct _Ellipse
    {
        double   Flattening;
        double   RotateAngle;
        int      Division;
        double   StandbyAngle;
    } Ellipse;

    // DeveloperMode
    struct _DeveloperMode
    {
        int      Enabled;
    } DeveloperMode;

    // KeyIndex
    struct _KeyIndex
    {
        string_t CopyValueToClipboard;
        string_t AdjustIncrementSmall;
        string_t AdjustDecrementSmall;
        string_t AdjustIncrementMedium;
        string_t AdjustDecrementMedium;
        string_t AdjustIncrementLarge;
        string_t AdjustDecrementLarge;
        string_t SwitchAdjustMode;
        string_t ResetAdjustValue;
    } KeyIndex;

    // StepValue
    struct _StepValue
    {
        double   Angle;
        double   Value;
        double   Rotate;
    } StepValue;

protected:

    string_t initGauge;
    string_t loadGauge;

    bool iniRW(string_t f, int r)    
    {                                
        string_t s;                  

        s = _T("SubjectKey");
        inimoni::inirw( r,f,s, _T("Subject          "), SubjectKey.Subject );

        s = _T("FileName");
        inimoni::inirw( r,f,s, _T("Gauge0        "), FileName.Gauge0 );
        inimoni::inirw( r,f,s, _T("Gauge1        "), FileName.Gauge1 );
        inimoni::inirw( r,f,s, _T("Gauge2        "), FileName.Gauge2 );
        inimoni::inirw( r,f,s, _T("Gauge3        "), FileName.Gauge3 );
        inimoni::inirw( r,f,s, _T("Gauge4        "), FileName.Gauge4 );
        inimoni::inirw( r,f,s, _T("Gauge5        "), FileName.Gauge5 );
        inimoni::inirw( r,f,s, _T("Gauge6        "), FileName.Gauge6 );
        inimoni::inirw( r,f,s, _T("Gauge7        "), FileName.Gauge7 );
        inimoni::inirw( r,f,s, _T("Gauge8        "), FileName.Gauge8 );
        inimoni::inirw( r,f,s, _T("Gauge9        "), FileName.Gauge9 );
        inimoni::inirw( r,f,s, _T("Gauge10       "), FileName.Gauge10 );
        inimoni::inirw( r,f,s, _T("Gauge11       "), FileName.Gauge11 );
        inimoni::inirw( r,f,s, _T("Gauge12       "), FileName.Gauge12 );
        inimoni::inirw( r,f,s, _T("Gauge13       "), FileName.Gauge13 );
        inimoni::inirw( r,f,s, _T("Gauge14       "), FileName.Gauge14 );
        inimoni::inirw( r,f,s, _T("Gauge15       "), FileName.Gauge15 );

        s = _T("PanelIndex");
		inimoni::inirw(r, f, s, _T("Needle           "), PanelIndex.Needle);
		inimoni::inirw(r, f, s, _T("Ellipse0         "), PanelIndex.Ellipse0);
		inimoni::inirw(r, f, s, _T("Ellipse1         "), PanelIndex.Ellipse1);
		inimoni::inirw(r, f, s, _T("Ellipse2         "), PanelIndex.Ellipse2);
		inimoni::inirw(r, f, s, _T("Ellipse3         "), PanelIndex.Ellipse3);
		inimoni::inirw(r, f, s, _T("Ellipse4         "), PanelIndex.Ellipse4);
		inimoni::inirw(r, f, s, _T("Ellipse5         "), PanelIndex.Ellipse5);
		inimoni::inirw(r, f, s, _T("Ellipse6         "), PanelIndex.Ellipse6);
		inimoni::inirw(r, f, s, _T("Ellipse7         "), PanelIndex.Ellipse7);
		inimoni::inirw(r, f, s, _T("Ellipse8         "), PanelIndex.Ellipse8);
		inimoni::inirw(r, f, s, _T("Ellipse9         "), PanelIndex.Ellipse9);
		inimoni::inirw(r, f, s, _T("Ellipse10        "), PanelIndex.Ellipse10);
		inimoni::inirw(r, f, s, _T("Ellipse11        "), PanelIndex.Ellipse11);
		inimoni::inirw(r, f, s, _T("Ellipse12        "), PanelIndex.Ellipse12);
		inimoni::inirw(r, f, s, _T("Ellipse13        "), PanelIndex.Ellipse13);
		inimoni::inirw(r, f, s, _T("Ellipse14        "), PanelIndex.Ellipse14);
		inimoni::inirw(r, f, s, _T("Ellipse15        "), PanelIndex.Ellipse15);
		inimoni::inirw(r, f, s, _T("Ellipse16        "), PanelIndex.Ellipse16);
		inimoni::inirw(r, f, s, _T("Ellipse17        "), PanelIndex.Ellipse17);
		inimoni::inirw(r, f, s, _T("Ellipse18        "), PanelIndex.Ellipse18);
		inimoni::inirw(r, f, s, _T("Ellipse19        "), PanelIndex.Ellipse19);
		inimoni::inirw(r, f, s, _T("Ellipse20        "), PanelIndex.Ellipse20);
		inimoni::inirw(r, f, s, _T("Ellipse21        "), PanelIndex.Ellipse21);
		inimoni::inirw(r, f, s, _T("Ellipse22        "), PanelIndex.Ellipse22);
		inimoni::inirw(r, f, s, _T("Ellipse23        "), PanelIndex.Ellipse23);
		inimoni::inirw(r, f, s, _T("Ellipse24        "), PanelIndex.Ellipse24);
		inimoni::inirw(r, f, s, _T("Ellipse25        "), PanelIndex.Ellipse25);
		inimoni::inirw(r, f, s, _T("Ellipse26        "), PanelIndex.Ellipse26);
		inimoni::inirw(r, f, s, _T("Ellipse27        "), PanelIndex.Ellipse27);
		inimoni::inirw(r, f, s, _T("Ellipse28        "), PanelIndex.Ellipse28);
		inimoni::inirw(r, f, s, _T("Ellipse29        "), PanelIndex.Ellipse29);
		inimoni::inirw(r, f, s, _T("Ellipse30        "), PanelIndex.Ellipse30);
		inimoni::inirw(r, f, s, _T("Ellipse31        "), PanelIndex.Ellipse31);
		inimoni::inirw(r, f, s, _T("Ellipse32        "), PanelIndex.Ellipse32);
		inimoni::inirw(r, f, s, _T("Ellipse33        "), PanelIndex.Ellipse33);
		inimoni::inirw(r, f, s, _T("Ellipse34        "), PanelIndex.Ellipse34);
		inimoni::inirw(r, f, s, _T("Ellipse35        "), PanelIndex.Ellipse35);
		inimoni::inirw(r, f, s, _T("Ellipse36        "), PanelIndex.Ellipse36);
		inimoni::inirw(r, f, s, _T("Ellipse37        "), PanelIndex.Ellipse37);
		inimoni::inirw(r, f, s, _T("Ellipse38        "), PanelIndex.Ellipse38);
		inimoni::inirw(r, f, s, _T("Ellipse39        "), PanelIndex.Ellipse39);
		inimoni::inirw(r, f, s, _T("Ellipse40        "), PanelIndex.Ellipse40);
		inimoni::inirw(r, f, s, _T("Ellipse41        "), PanelIndex.Ellipse41);
		inimoni::inirw(r, f, s, _T("Ellipse42        "), PanelIndex.Ellipse42);
		inimoni::inirw(r, f, s, _T("Ellipse43        "), PanelIndex.Ellipse43);
		inimoni::inirw(r, f, s, _T("Ellipse44        "), PanelIndex.Ellipse44);
		inimoni::inirw(r, f, s, _T("Ellipse45        "), PanelIndex.Ellipse45);
		inimoni::inirw(r, f, s, _T("Ellipse46        "), PanelIndex.Ellipse46);
		inimoni::inirw(r, f, s, _T("Ellipse47        "), PanelIndex.Ellipse47);
		inimoni::inirw(r, f, s, _T("Ellipse48        "), PanelIndex.Ellipse48);
		inimoni::inirw(r, f, s, _T("Ellipse49        "), PanelIndex.Ellipse49);
		inimoni::inirw(r, f, s, _T("Ellipse50        "), PanelIndex.Ellipse50);
		inimoni::inirw(r, f, s, _T("Ellipse51        "), PanelIndex.Ellipse51);
		inimoni::inirw(r, f, s, _T("Ellipse52        "), PanelIndex.Ellipse52);
		inimoni::inirw(r, f, s, _T("Ellipse53        "), PanelIndex.Ellipse53);
		inimoni::inirw(r, f, s, _T("Ellipse54        "), PanelIndex.Ellipse54);
		inimoni::inirw(r, f, s, _T("Ellipse55        "), PanelIndex.Ellipse55);
		inimoni::inirw(r, f, s, _T("Ellipse56        "), PanelIndex.Ellipse56);
		inimoni::inirw(r, f, s, _T("Ellipse57        "), PanelIndex.Ellipse57);
		inimoni::inirw(r, f, s, _T("Ellipse58        "), PanelIndex.Ellipse58);
		inimoni::inirw(r, f, s, _T("Ellipse59        "), PanelIndex.Ellipse59);
		inimoni::inirw(r, f, s, _T("Ellipse60        "), PanelIndex.Ellipse60);
		inimoni::inirw(r, f, s, _T("Ellipse61        "), PanelIndex.Ellipse61);
		inimoni::inirw(r, f, s, _T("Ellipse62        "), PanelIndex.Ellipse62);
		inimoni::inirw(r, f, s, _T("Ellipse63        "), PanelIndex.Ellipse63);
        s = _T("Vibration");
        inimoni::inirw( r,f,s, _T("Period           "), Vibration.Period   );
        inimoni::inirw( r,f,s, _T("Amplitude        "), Vibration.Amplitude );
        inimoni::inirw( r,f,s, _T("Threshold        "), Vibration.Threshold );

        s = _T("Damping");
        inimoni::inirw( r,f,s, _T("NaturalFreq      "), Damping.NaturalFreq );
        inimoni::inirw( r,f,s, _T("DampingRatio     "), Damping.DampingRatio );

        s = _T("Ellipse");
        inimoni::inirw( r,f,s, _T("Flattening       "), Ellipse.Flattening );
        inimoni::inirw( r,f,s, _T("RotateAngle      "), Ellipse.RotateAngle );
        inimoni::inirw( r,f,s, _T("Division  "), Ellipse.Division );
        inimoni::inirw( r,f,s, _T("StandbyAngle     "), Ellipse.StandbyAngle );

        s = _T("DeveloperMode");
        inimoni::inirw( r,f,s, _T("Enabled          "), DeveloperMode.Enabled );

        s = _T("KeyIndex");
        inimoni::inirw( r,f,s, _T("CopyValueToClipboard"), KeyIndex.CopyValueToClipboard );
        inimoni::inirw( r,f,s, _T("AdjustIncrementSmall"), KeyIndex.AdjustIncrementSmall );
        inimoni::inirw( r,f,s, _T("AdjustDecrementSmall"), KeyIndex.AdjustDecrementSmall );
        inimoni::inirw( r,f,s, _T("AdjustIncrementMedium"), KeyIndex.AdjustIncrementMedium );
        inimoni::inirw( r,f,s, _T("AdjustDecrementMedium"), KeyIndex.AdjustDecrementMedium );
        inimoni::inirw( r,f,s, _T("AdjustIncrementLarge"), KeyIndex.AdjustIncrementLarge );
        inimoni::inirw( r,f,s, _T("AdjustDecrementLarge"), KeyIndex.AdjustDecrementLarge );
        inimoni::inirw( r,f,s, _T("SwitchAdjustMode "), KeyIndex.SwitchAdjustMode );
        inimoni::inirw( r,f,s, _T("ResetAdjustValue "), KeyIndex.ResetAdjustValue );

        s = _T("StepValue");
        inimoni::inirw( r,f,s, _T("Angle            "), StepValue.Angle    );
        inimoni::inirw( r,f,s, _T("Value            "), StepValue.Value    );
        inimoni::inirw( r,f,s, _T("Rotate           "), StepValue.Rotate   );
        return true;                                                    
    }                                                                   

    void init()                                                         
    {                                                                   
        SubjectKey.Subject           = _T("kmph");
        FileName.Gauge0           = _T("null");
        FileName.Gauge1           = _T("null");
        FileName.Gauge2           = _T("null");
        FileName.Gauge3           = _T("null");
        FileName.Gauge4           = _T("null");
        FileName.Gauge5           = _T("null");
        FileName.Gauge6           = _T("null");
        FileName.Gauge7           = _T("null");
        FileName.Gauge8           = _T("null");
        FileName.Gauge9           = _T("null");
        FileName.Gauge10          = _T("null");
        FileName.Gauge11          = _T("null");
        FileName.Gauge12          = _T("null");
        FileName.Gauge13          = _T("null");
        FileName.Gauge14          = _T("null");
        FileName.Gauge15          = _T("null");
        PanelIndex.Needle            = -1;
        PanelIndex.Ellipse0          = -1;
        PanelIndex.Ellipse1          = -1;
        PanelIndex.Ellipse2          = -1;
        PanelIndex.Ellipse3          = -1;
        PanelIndex.Ellipse4          = -1;
        PanelIndex.Ellipse5          = -1;
        PanelIndex.Ellipse6          = -1;
        PanelIndex.Ellipse7          = -1;
        PanelIndex.Ellipse8          = -1;
        PanelIndex.Ellipse9          = -1;
        PanelIndex.Ellipse10         = -1;
        PanelIndex.Ellipse11         = -1;
        PanelIndex.Ellipse12         = -1;
        PanelIndex.Ellipse13         = -1;
        PanelIndex.Ellipse14         = -1;
        PanelIndex.Ellipse15         = -1;
        PanelIndex.Ellipse16         = -1;
        PanelIndex.Ellipse17         = -1;
        PanelIndex.Ellipse18         = -1;
        PanelIndex.Ellipse19         = -1;
        PanelIndex.Ellipse20         = -1;
        PanelIndex.Ellipse21         = -1;
        PanelIndex.Ellipse22         = -1;
        PanelIndex.Ellipse23         = -1;
        PanelIndex.Ellipse24         = -1;
        PanelIndex.Ellipse25         = -1;
        PanelIndex.Ellipse26         = -1;
        PanelIndex.Ellipse27         = -1;
        PanelIndex.Ellipse28         = -1;
        PanelIndex.Ellipse29         = -1;
        PanelIndex.Ellipse30         = -1;
        PanelIndex.Ellipse31         = -1;
		PanelIndex.Ellipse32 = -1;
		PanelIndex.Ellipse33 = -1;
		PanelIndex.Ellipse34 = -1;
		PanelIndex.Ellipse35 = -1;
		PanelIndex.Ellipse36 = -1;
		PanelIndex.Ellipse37 = -1;
		PanelIndex.Ellipse38 = -1;
		PanelIndex.Ellipse39 = -1;
		PanelIndex.Ellipse40 = -1;
		PanelIndex.Ellipse41 = -1;
		PanelIndex.Ellipse42 = -1;
		PanelIndex.Ellipse43 = -1;
		PanelIndex.Ellipse44 = -1;
		PanelIndex.Ellipse45 = -1;
		PanelIndex.Ellipse46 = -1;
		PanelIndex.Ellipse47 = -1;
		PanelIndex.Ellipse48 = -1;
		PanelIndex.Ellipse49 = -1;
		PanelIndex.Ellipse50 = -1;
		PanelIndex.Ellipse51 = -1;
		PanelIndex.Ellipse52 = -1;
		PanelIndex.Ellipse53 = -1;
		PanelIndex.Ellipse54 = -1;
		PanelIndex.Ellipse55 = -1;
		PanelIndex.Ellipse56 = -1;
		PanelIndex.Ellipse57 = -1;
		PanelIndex.Ellipse58 = -1;
		PanelIndex.Ellipse59 = -1;
		PanelIndex.Ellipse60 = -1;
		PanelIndex.Ellipse61 = -1;
		PanelIndex.Ellipse62 = -1;
		PanelIndex.Ellipse63 = -1;
        Vibration.Period             = 0.0;
        Vibration.Amplitude          = 0.0;
        Vibration.Threshold          = 0.0;
        Damping.NaturalFreq          = 0.0;
        Damping.DampingRatio         = 0.0;
        Ellipse.Flattening           = 0.0;
        Ellipse.RotateAngle          = 0.0;
        Ellipse.Division             = 0;
        Ellipse.StandbyAngle         = 180.0;
        DeveloperMode.Enabled        = 0;
        KeyIndex.CopyValueToClipboard = _T("S");
        KeyIndex.AdjustIncrementSmall = _T("A1");
        KeyIndex.AdjustDecrementSmall = _T("A2");
        KeyIndex.AdjustIncrementMedium = _T("B1");
        KeyIndex.AdjustDecrementMedium = _T("B2");
        KeyIndex.AdjustIncrementLarge = _T("C1");
        KeyIndex.AdjustDecrementLarge = _T("C2");
        KeyIndex.SwitchAdjustMode    = _T("D");
        KeyIndex.ResetAdjustValue    = _T("L");
        StepValue.Angle              = 1.0;
        StepValue.Value              = 10.0;
        StepValue.Rotate             = 1.0;
    }                                                                   
};
typedef AtsIni AtsFile; //êVãåå›ä∑

//---------------------------------------------------------------------------
// Common method                                                             
//---------------------------------------------------------------------------
#ifndef INIMONI_INIRW                                                        
#define INIMONI_INIRW                                                        
namespace inimoni                                                            
{                                                                            
    /*                                                                       
    Read and Write INI file                                                  
      int     is_read  1=Read mode, 0=Write mode                             
      string  fname    Gauge (The Windows folder when there is not path)  
      string  sec      Section name                                          
      string  key      Key name                                              
      T       val_t    [Read]Init+Output, [Write]Input                       
    */                                                                       
    template<class T>                                                        
	static bool inirw(int is_read, string_t& fname, string_t sec, string_t key, T& val_t)
	{                                                                        
		if(is_read){                                                         
            inimoni::read(fname.c_str(), sec.c_str(), key.c_str(), val_t);   
        }                                                                    
        else{                                                                
			inimoni::write(fname.c_str(), sec.c_str(), key.c_str(), val_t);  
        }                                                                    
		return true;                                                         
    }                                                                        
                                                                             
	static bool read(string_t ifn, string_t sec, string_t key, int& dst)
    {                                                                        
        dst = GetPrivateProfileInt( sec.c_str(), key.c_str(), dst, ifn.c_str() );
        return true;                                                         
    }                                                                        
                                                                             
	static bool read(string_t ifn, string_t sec, string_t key, basic_string<TCHAR>& dst)
    {                                                                        
        TCHAR buf[256];                                                      
        GetPrivateProfileString(                                             
            sec.c_str(),                                                     
            key.c_str(),                                                     
            dst.c_str(),                                                     
            buf,                                                             
            sizeof(buf),                                                     
            ifn.c_str() );                                                   
        dst = buf;                                                           
        return true;                                                         
    }                                                                        
                                                                             
	static bool read(string_t ifn, string_t sec, string_t key, double& dst)
    {                                                                        
        string_t s;                                                          
        inimoni::read(ifn, sec, key, s);                                     
                                                                             
        TCHAR* e;                                                            
        double x = _tcstod(s.c_str(), &e);                                   
                                                                             
        //dst = 0.0;                                                           
        if (!*e && s != "") {                                                           
            dst = x;                                                         
        }                                                                    
        return true;                                                         
    }                                                                        
                                                                             
    template<class T>                                                        
	static bool write(string_t ifn, string_t sec, string_t key, T val_t)
    {                                                                        
        TCHAR val[1024];                                                     
        inimoni::to_string(val, val_t);                                      
        WritePrivateProfileString( sec.c_str(), key.c_str(), val, ifn.c_str() );
		return true;                                                    
	}                                                                   
                                                                        
	static void to_string(TCHAR* str, int val)
    {                                                                   
        _stprintf( str, _T("%d"), val );                                
    }                                                                   
                                                                        
	static void to_string(TCHAR* str, double val)
    {                                                                   
        _stprintf( str, _T("%f"), val );                                
    }                                                                   
                                                                        
    static void to_string(TCHAR* str, basic_string<TCHAR> val)                 
    {                                                                   
        _stprintf( str, _T("%s"), val.c_str() );                        
    }                                                                   
};                                                                      
                                                                        
#endif                                                                  
#endif                                                                  

