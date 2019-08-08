#include "Hello.h"
#include <iostream>

JNIEXPORT void JNICALL Java_Hello_jniSayHello__(JNIEnv* env, jobject self) {
    std::cout << "Hello from JNI!" << std::endl;
}

JNIEXPORT void JNICALL Java_Hello_jniSayHello__I(JNIEnv* env, jobject self, jint a){
	std::cout << "Hello from JNI!" << a << std::endl;
}
JNIEXPORT void JNICALL Java_Hello_jniSayClass(JNIEnv* env, jobject self, jobject t){
    jclass jcls = env->GetObjectClass(t);

    // First, get the class object

    jmethodID mid = env->GetMethodID(jcls, "getClass", "()Ljava/lang/Class;");

    jobject clsObj = env->CallObjectMethod(t, mid);

    // Now get the class object's class descriptor

    jcls = env->GetObjectClass(clsObj);

    mid = env->GetMethodID(jcls, "getName", "()Ljava/lang/String;");

    jstring className = static_cast<jstring>(env->CallObjectMethod(clsObj, mid));

    const char* str = env->GetStringUTFChars(className, NULL);

    std::cout << "Class Name by JNI:" << str << std::endl;

    env->ReleaseStringUTFChars(className, str);
}
JNIEXPORT void JNICALL Java_Hello_jniLoadObject(JNIEnv* env, jobject self, jobject t){


    jclass jcls = env->GetObjectClass(t);

    // First, get the class object

    jmethodID mid = env->GetMethodID(jcls, "getClass", "()Ljava/lang/Class;");

    jobject clsObj = env->CallObjectMethod(t, mid);

    // Now get the class object's class descriptor

    jcls = env->GetObjectClass(clsObj);

    mid = env->GetMethodID(jcls, "getDeclaredFields", "()[Ljava/lang/reflect/Field;");
    std::cout << "good" << std::endl;
    jobjectArray fieldArray =static_cast<jobjectArray>(env->CallObjectMethod(clsObj, mid));
    std::cout << "bad" << std::endl;
    jint i;

    jint count = env->GetArrayLength(fieldArray);

    for(i=0; i< count; i++){
        jobject jo = (env->GetObjectArrayElement(fieldArray,i));
	jclass jcls2 = env->GetObjectClass(jo);
        jmethodID md = env->GetMethodID(jcls2, "getName", "()Ljava/lang/String;");
	jstring fieldName = static_cast<jstring>(env->CallObjectMethod(jo,md));
	const char* str2 = env->GetStringUTFChars(fieldName, NULL);
	std::cout << "Field Name:" << str2 << std::endl;
	env->ReleaseStringUTFChars(fieldName, str2);
    }

}
