# MyGPS
秋月電子GPSモジュール用ライブラリ
対応モジュール：
秋月電子 AE-GYSFDMAXB(ディスコンになってしまいました)
秋月電子 AE-GNSS-EXTANT(注意:AE-GYSFDMAXBとRX,TXピンが逆)
GT-902PMGG(注意:日付情報が3分程度しか保持されない)


ArduinoでGPSのシリアル出力をデコードするライブラリ。
緯度経度、補足衛星数と時間情報が得られる。
複数のシリアル入出力ができるArduino MEGA用になっているため、Arduino UNOで使用する場合ポートを書き換える必要がある。
(メモリが足りないのでUNOは推奨しない)
GPSモジュールの出力を受け取るだけで、Arduino側からGPSモジュールに信号を送ることはないので、Arduino->GPS側は結線不要。
ただし、GPSモジュールのRXに何もつながないと不具合が生じる(いつまでたってもキャリブレーションが終わらない)ので、
接続しない配線は3.3Vでプルアップすること。

旧AE-GYSFDMAXBと新しいAE-GNSS-EXTANTの出力データはよく似ているが、ピンの配列が変わっているので注意が必要。
GT-902PMGGは安価なのとバラ線なので配線に融通が効くが日付情報が長時間保持できないのでRTC的な使い方には向かない。
