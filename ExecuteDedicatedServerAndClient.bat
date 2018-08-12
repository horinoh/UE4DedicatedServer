@rem Cooked data output directory
@set DST=WindowsNoEditor\UE4DedicatedServer\Binaries\Win64

@rem Executable file name
@set SERVER=UE4DedicatedServerServer.exe
@set CLIENT=UE4DedicatedServer.exe

@rem On client, input "open 127.0.0.1" from console
start %DST%\%SERVER% -log
start %DST%\%CLIENT% -log -ResX=640 -ResY=360
