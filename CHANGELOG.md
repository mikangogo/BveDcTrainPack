# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- 新しい車両パックを新規作成。
  - キハ183
  - キハ52
  - キハ40
  - キハ30
  - キハ20
- ライセンスを設定。
- 重要告知事項を追加。
- `./Plugin/ThridParty/Onemanhoso` に「ワンマン放送プラグイン(Xaudio2版)」を追加。作者: [@AskED757001](https://twitter.com/AskED757001) さん
- PluginOrganizer: 各プラグインの読み込み前にファイル移動など初期化・下準備ができるようなコマンドを実行できる機能を追加。
- CLE: いくつかの音再生機能（減圧音など）を追加。
- DMF15HSA: 機関ブレーキ表示灯を実装。

### Changed
- CLE: C26ブレーキ制御装置とC36ブレーキ制御装置に分離。
- CLE: 車両数に応じてブレーキの応答性が変わるように変更。
- PluginOrganizer: Yamlのバージョンを 1.1.00 へ変更。
- PluginOrganizer: 書式を変更。
