----------------------------------------
Bvets Status Window - Version 1.1
----------------------------------------

■概要
ATSプラグインから得られる各種情報を
ウィンドウ上に一覧表示するATSプラグインです。
アドオン制作の補助ツールとしてご利用ください。

不具合報告・要望等のご連絡は末尾に記載のメールアドレスもしくは
Twitterアカウントへのリプライ・ダイレクトメールにて承ります。

■動作環境
Microsoft .NET Framework Version 2.0と
Microsoft Visual C++ 2008 再頒布可能パッケージ (x86) が
インストールされているWindows上で動作します。

上記ランタイムをインストールされていない場合は、
以下のリンクよりダウンロード・インストールしてください。

.NET Framework Version 2.0
http://www.microsoft.com/ja-jp/download/details.aspx?id=1639

Microsoft Visual C++ 2008 再頒布可能パッケージ (x86) 
https://www.microsoft.com/ja-jp/download/details.aspx?id=29

■導入
原則としてRock_On様作成のDetailManagerを利用し、
複数のATSプラグインを組み合わせて使用します。
基本的には最後に当プラグインが処理されるよう、
DetailModules.txtの最後尾に当プラグインへのパスを記述します。
ただし、定速制御を行うプラグインが含まれている場合は
その前に読み込まれるようにします。

情報表示ウィンドウはプラグインの
読み込みと同時に自動表示されます。

■既知の不具合
DetailManagerの設定ファイルで当プラグインへのパスを指定を行う際、
上の階層の相対パス(..\)を含めると最初は正常に読み込めても
リロード時にフリーズするという不具合を確認しています。

現時点ではこの不具合の解決の見込みが立っておりませんので、
上の階層への相対パスの使用は避けてのご利用をお願いします。

・フリーズを起こすパス設定例
..\BvetsStatusWindow.dll
..\Ats\BvetsStatusWindow.dll

・正常動作するパス設定例
BvetsStatusWindow.dll
Ats\BvetsStatusWindow.dll

■設定ファイル
csv形式の設定ファイルにより表示をカスタマイズできます。
仕様の詳細につきましてはダウンロードページをご覧ください。

■設定ファイルのサンプル
Settings-Sampleフォルダ内に他作者様のATSプラグインに対応した
サンプル設定ファイルを同梱しております。設定ファイル作成の
参考にしてみてください。

なお、設定ファイルサンプルに対する各プラグイン作者様への
お問い合わせはご遠慮ください。

■ソースコード
srcフォルダ内に当プラグインのソースコードを添付しています。
コンパイルにはVisual Studio 2013以降が必要になります。

■ライセンス
当アプリケーションにはMITライセンスを適用します。
著作者表記とライセンス文章の改変を行わない限り、当アプリケーションを
自由に利用することができます。ただし、当アプリケーションを利用したことにより
発生しうるいかなる損害についてBVE Workshopはその責を負わないものとします。

■更新履歴
2015-09-19 Version 1.1
画面のちらつきを解消
ラベル設定ファイルの名前や格納フォルダを任意に設定可能に
ラベル設定ファイルとしてタブ区切りテキストにも対応
表示可能な状態量にフレームレートを追加
一部の状態数値の表示書式変更を可能に
ソースコードを同梱

2015-09-19
ライセンス文章の追加

2015-09-13
公開

----------------------------------------
BVE Workshop

Website : http://bvews.jpn.org/
Twitter : https://twitter.com/bve_ws
E-mail  : bveworkshop@bvews.jpn.org
----------------------------------------