# 気動車車両パック

これは Bve trainsim 用の気動車車両パックです。

# 使用方法

- 本フォルダを任意の場所に配置し、使用したい車両データのパスをシナリオへ通します。
  
  例: キハ20形式車両データであれば、`${Root}\Vehicle\Kiha20\Original\Vehicle_Kiha20.txt`のようになります。

# 動作環境

シミュレートのための計算量が多く、デスクトップ向けのCPUが必要です。

以下の環境にて制作・動作の確認をしております。

- Core i7 14700KF

また、他では以下の環境にて動作している報告を受けています。

- 第4世代デスクトップ向け Core プロセッサ
- 第8世代デスクトップ向け Core プロセッサ

# 本パックを使用して派生作品を作られる方へ

## AutomaticBrakeSystem.dllの仕様

### PluginParameters.txt

- [こちら](./Docs/)に PluginParameters.txt 経由で設定可能な全パラメータの一覧を置きました。
  
  とりあえず置いただけで整備が為されていないので注意…。

- 編成内の車両ごとにブレーキシステムを変更可能となっています。
  - 気動車一般編成: キハ80系列、キハ183系列をのぞく全ての車両が混在可。従来通りの PluginParameters.txt の記述も可。
  - キハ80系列編成: キハ80系列の車のみで組成可。
  - キハ183系列編成: キハ183基本番台、500/1500代の車のみで組成可。

### プラグインからの出力

- Panel[81]: ダイナミックブレーキ　指令信号

### プラグインへの入力

- Panel[80]: 機関回転数 [rpm]
- Panel[82]: ダイナミックブレーキ　コンバータ起動信号
- Panel[83]: ダイナミックブレーキ　コンバータ動作中信号

## BveHooker.dllの仕様

### Bve側からの出力

- Panel[85]: 空車自重と現在の自重の比 x 1000.0

### Bve側への入力

- Panel[86]: M車BC圧 [Pa]
- Panel[87]: T車BC圧 [Pa]
- Panel[88]: M車PistonArea [m2] x 10000000.0
- Panel[89]: T車PistonArea [m2] x 10000000.0
- Panel[90]: M車ShoeFriction A x 10000000.0
- Panel[91]: M車ShoeFriction B x 10000000.0
- Panel[92]: M車ShoeFriction C x 10000000.0
- Panel[93]: T車ShoeFriction A x 10000000.0
- Panel[94]: T車ShoeFriction B x 10000000.0
- Panel[95]: T車ShoeFriction C x 10000000.0
- Panel[101]: 運転台パネルER圧 [Pa]
- Panel[102]: 運転台パネルMR圧 [Pa]
- Panel[103]: 運転台パネルBP圧 [Pa]
- Panel[104]: 運転台パネルBC圧 [Pa]
- Panel[105]: 運転台パネルSAP圧 [Pa]

## 関連ドキュメント

- [重要告知事項](NOTICE.md)
- [ライセンス](LICENSE.md)
