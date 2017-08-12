# 専用サーバ

## [パッケージ化](https://github.com/horinoh/UE4DedicatedServer/tree/master/Document/Packaging)する

## ビルド
* XXX**Server**.Target.cs を作成 (基本XXX**Editor**.Target.cs をコピーして作成)
  * .uproject 右クリック - Generate Visual Studio project files
  * Visual Studio を開いてコンフィギュレーションを Development Server にしてビルド
    * Binaries/Win64/XXXServer.exe へ実行ファイルが作成される
  * 実行ファイルを**パッケージ化先ディレクトリ**へコピーする
    * ここでは CopyDedicatedServer.bat を作成したので、これを実行
    * XXX.exe はパッケージ化で作成されるが、XXXServer.exe は作成されない為、明示的にコピーしている
  * サーバとクライアントを起動する
    * ここでは ExecuteDedicatedServerAndClient.bat を作成したので、これを実行
    * -log をつけるとログウィンドウが出る
    * クライアントコンソール(@)から `open 127.0.0.1:7777`。サーバに入れたら成功