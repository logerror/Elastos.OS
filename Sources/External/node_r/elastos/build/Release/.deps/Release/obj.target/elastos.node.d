cmd_Release/obj.target/elastos.node := arm-linux-androideabi-g++ -shared -pthread -rdynamic --sysroot=/home/jingcao/Workspace2/Elastos5/Build/Prebuilt/Linux -L/home/jingcao/Workspace2/Elastos5/Build/Prebuilt/Linux/usr/lib  -Wl,-soname=elastos.node -o Release/obj.target/elastos.node -Wl,--start-group Release/obj.target/elastos/addon/elastos_root.o -Wl,--end-group /home/jingcao/Workspace2/Elastos5/Targets/obj/rdk/arm.gnu.android.dbg/lib/Elastos.Runtime.lib /home/jingcao/Workspace2/Elastos5/Targets/rdk/arm.gnu.android.dbg/bin/Elastos.Runtime.eco /home/jingcao/Workspace2/Elastos5/Targets/rdk/arm.gnu.android.dbg/bin/Elastos.CoreLibrary.eco /home/jingcao/Workspace2/Elastos5/Targets/obj/rdk/arm.gnu.android.dbg/lib/crt0.lib -licuuc -licui18n -llog -lnode
