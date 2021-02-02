#include <jni.h>
#include <string>
#include "SFML/Graphics.hpp"


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_sfmltemplate_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    sf::CircleShape shape(100.f);
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



