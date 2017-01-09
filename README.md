# UE4Server

* パッケージ化
  * File - Package Project - Package Settings でパッケージ化の設定
    * とりあえず以下にチェックを入れた
      * FullRebuild
      * Include Prerequisties
      * Create compressed coocked packages
  * File - Package Project - Windows - Windows (64bit) - 出力先ディレクトリを指定して出力
    * ここでは Package ディレクトリを作成して指定した
  
* XXXX**Server**.Target.cs を作成 (基本 XXXX**Editor**.Target.cs をコピーして作成)
  * .uproject 右クリック - Generate Visual Studio project files
* Visual Studio を開いてコンフィギュレーションを Development Server にしてビルド
  * Binaries/Win64/XXXXServer.exe へ実行ファイルが作成される
* 実行ファイルを**パッケージ化先ディレクトリ**へコピーする
  * ここでは CopyDedicatedServer.bat を作成した
* サーバとクライアントを起動する
  * ここでは ExecuteDedicatedServerAndClient.bat を作成した
  * -log をつけるとログウィンドウが出る
  * クライアントのコンソール(@)から `open 127.0.0.1`
  * サーバに入れたら(地面が赤いマップへ移動)成功