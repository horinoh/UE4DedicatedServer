# 専用サーバ

## [パッケージ化 Packaging](https://github.com/horinoh/UE4DedicatedServer/tree/master/Document/Packaging)

## ビルド Build
* XXX**Server**.Target.cs を作成 (基本XXX**Editor**.Target.cs をコピーして作成) Create XXX**Server**.Target.cs (Basically copy of XXX**Editor**.Target.cs)
  * XXX.uproject - Generate Visual Studio project files
  * Visual Studio を開いてコンフィギュレーションを Development Server にしてビルド In Visual Studio build with configuration "Development Server"
    * Binaries/Win64/XXXServer.exe へ実行ファイルが作成される Executable is created to Binaries/Win64/XXXServer.exe
  * 実行ファイルを**パッケージ化先ディレクトリ**へコピーする Copy executable to **Packaging directory**
    * ここでは CopyDedicatedServer.bat を作成したので、これを実行 In this case I created CopyDedicatedServer.bat
    * XXXServer.exe は作成されない為、明示的にコピーしている Because XXXServer.exe is not created in packaging process, I copy explicitly
  * サーバとクライアントを起動する Invoke server and client
    * ここでは ExecuteDedicatedServerAndClient.bat を作成したので、これを実行 In this case I created ExecuteDedicatedServerAndClient.bat
    * -log をつけるとログウィンドウが出る With -log option log window will appear
    * クライアントコンソール(@)から `open 127.0.0.1`。サーバに入れたら成功 From client console(~)`open 127.0.0.1`. If entered server, it's OK