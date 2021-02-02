# sfmltemplate

### 1. Build SFML
- Fetch SFML repo
```
git clone https://github.com/SFML/SFML.git
```
- Disable SFML_BUILD_AUDIO (TRUE -> FALSE
```
sfml_set_option(SFML_BUILD_AUDIO FALSE BOOL "TRUE to build SFML's Audio module.")
```
- Run following in SFML/build
```
NDK_PATH="/home/taras/Android/Sdk/ndk/21.1.6352462/"

ABI=armeabi-v7a

cmake -DANDROID_ABI=$ABI -DANDROID_PLATFORM=android-21 \
    -stdlib=libc++ -DCMAKE_TOOLCHAIN_FILE=${NDK_PATH}build/cmake/android.toolchain.cmake \
    -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=clang \
    -DCMAKE_SYSTEM_NAME=Android -DCMAKE_ANDROID_NDK=${NDK_PATH} \
    -DCMAKE_SFML_BUILD_AUDIO=FALSE \
    -D"OPENAL_INCLUDE_DIR=${NDK_PATH}/sources/sfml/extlibs/headers/AL/" \
    -D"OPENAL_LIBRARY=${NDK_PATH}/sources/sfml/extlibs/libs-android/${ABI}/" \
    -D"VORBIS_INCLUDE_DIR=${NDK_PATH}/sources/sfml/extlibs/headers/vorbis/" \
    -D"VORBIS_LIBRARIES=${NDK_PATH}/sources/sfml/extlibs/libs-android/${ABI}/libvorbis.a" \
    -D"OGG_INCLUDE_DIR=${NDK_PATH}/sources/sfml/extlibs/headers/ogg/" \
    -D"FREETYPE_INCLUDE_DIR_freetype2=${NDK_PATH}/sources/sfml/extlibs/headers/freetype2/" \
    -D"FREETYPE_INCLUDE_DIR_ft2build=${NDK_PATH}/sources/sfml/extlibs/headers/freetype2/" \
    -D"FREETYPE_LIBRARY=${NDK_PATH}/sources/sfml/extlibs/libs-android/${ABI}/libfreetype.a" \
    -DCMAKE_ANDROID_STL_TYPE=c++_static -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
make -j8
make install
```
- It will build libs into {NDK_PATH}/sources/third_party/sfml/lib/

### 2. Link Libs
- Check [CMakeLists.txt](https://github.com/jackersson/sfmltemplate/blob/main/app/src/main/cpp/CMakeLists.txt)
- Check [build.gradle](https://github.com/jackersson/sfmltemplate/blob/main/app/build.gradle#L19)
- Copy everything from {NDK_PATH}/sources/third_party/sfml/lib/, {NDK_PATH}sources/third_party/sfml/extlibs/lib/ to jniLibs
