# MyGPS
秋月電子GPSモジュール用ライブラリ(Arduino MEGA用)

対応モジュール：

・秋月電子 AE-GYSFDMAXB(ディスコンになってしまいました)

・秋月電子 AE-GNSS-EXTANT(注意:AE-GYSFDMAXBとRX,TXピンが逆)

・GT-902PMGG(注意:日付情報が3分程度しか保持されない)

--------------------------------------------------

ArduinoでGPSのシリアル出力をデコードするライブラリ。

緯度経度、補足衛星数と時間情報が得られる。

複数のシリアル入出力ができるArduino MEGA用になっているため、Arduino UNOで使用する場合ポートを書き換える必要がある。(メモリが足りないのでUNOは推奨しない)

GPSモジュールの出力を受け取るだけで、Arduino側からGPSモジュールに信号を送ることはないので、Arduino->GPS側は結線不要。

ただし、GPSモジュールのRXに何もつながないと不具合が生じる(いつまでたってもキャリブレーションが終わらない)ので、

接続しない配線は3.3Vでプルアップすること。

旧AE-GYSFDMAXBと新しいAE-GNSS-EXTANTの出力データはよく似ているが、ピンの配列が変わっているので注意が必要。

GT-902PMGGは安価なのとバラ線なので配線に融通が効くが日付情報が長時間保持できないのでRTC的な使い方には向かない。

--------------------------------------------------
結線方法

Arduino RX1(19pin)->GPS TX

Arduino 5V        ->GPS 5V

Arduino GND       ->GPS GND

Arduino 3.3V->10kΩ->GPS RX

--------------------------------------------------
License

Copyright 2023 Hideto Kurosaki

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in the
Software without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
