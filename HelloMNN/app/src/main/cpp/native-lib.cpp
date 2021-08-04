#include <jni.h>
#include <string>

#include <MNN/Interpreter.hpp>
#include <MNN/MNNDefine.h>
#include <MNN/Tensor.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hellomnn_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    std::vector<int> shape{1, 800};
    auto tensor = MNN::Tensor::create<float>(shape, NULL, MNN::Tensor::CAFFE);
    std::string hello = "Hello from MNN, create tensor Size: " + std::to_string(tensor->size());
    delete tensor;
    return env->NewStringUTF(hello.c_str());
}