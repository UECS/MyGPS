//MyGPS Library
//秋月電子AE-GYSFDMAXB GPSモジュール用ライブラリ
//Arduino MEGA用 GPSはシリアルポート1に接続、設定は工場出荷時のままで構わない。
//GPS->Arduino側は直結して構わないが、Arduino->GPSは接続せずGPSのRXはプルダウンすること(電圧レベルが違うため)。
//開発：UECS研究会
//Ver1.0 2021/10/6
//このライブラリはArduno標準ライブラリがあれば単体でも使用できる
/*
ライセンス
CC BY 4.0
https://creativecommons.org/licenses/by/4.0/
You are free to:
Share
	copy and redistribute the material in any medium or format
Adapt
	remix, transform, and build upon the material
	for any purpose, even commercially.
	This license is acceptable for Free Cultural Works.
	The licensor cannot revoke these freedoms as long as you follow the license terms.

Under the following terms:
Attribution 
	You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
	No additional restrictions ? You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.

Notices:
	You do not have to comply with the license for elements of the material in the public domain or where your use is permitted by an applicable exception or limitation.
	No warranties are given. The license may not give you all of the permissions necessary for your intended use. For example, other rights such as publicity, privacy, or moral rights may limit how you use the material.
*/

#ifndef _GPS_H_
#define _GPS_H_

#include "Arduino.h"

#define GPS_SERIAL_NG  -1  
#define GPS_SERIAL_OTHER 0
#define GPS_SERIAL_ZDA 1
#define GPS_SERIAL_GSV 2
#define GPS_SERIAL_GLL 3
	
#define JST 9 //Japan Standard Time

#define SERIAL_BUFFSIZE 80

#define PAI 3.14159265359
#define TO_RAD 0.01745329251


class GPS {
  public:
bool GPSSts;//GPSが使えるか
bool TimeSts;//時間情報が有効化どうか
bool PositionSts;//位置情報が有効かどうか
long UECSDate;
long UECSTime;
long Year;
long Mon;
long Day;
long Hour;
long Min;
long Sec;
double HourOfTheToday;//今日が始まってからの経過時間
long DayOfTheYear;//元旦からの経過日数
double SolarAltDeg;
double SolarAziDeg;
double LatitudeDeg;
double LongitudeDeg;
int Satellites;//補足した衛星の数

bool begin();
bool GPSRead();
void CalcSun(double longitude_deg,double latitude_deg);

  private:
char gps_txt[SERIAL_BUFFSIZE];
const int monthday[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
const int monthday_l[13]={31,31,29,31,30,31,30,31,31,30,31,30,31};
int DecodeGPS();
void DecodeZDA();
void DecodeGLL();
void DecodeGSV();
int SkipComma(int i);
int SkipDot(int i);



};


#endif
