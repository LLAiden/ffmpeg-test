#include <jni.h>
#include <string>
#include <unistd.h>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libavcodec/jni.h>

JNIEXPORT jstring JNICALL
Java_com_example_ffmpeg_1test_MainActivity_ffmpegInfo(
        JNIEnv *env,
        jobject /* this */) {

    char info[40000] = {0};
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL) {
        if (c_temp->decode != NULL) {
            sprintf(info, "%sdecode:", info);
            switch (c_temp->type) {
                case AVMEDIA_TYPE_VIDEO:
                    sprintf(info, "%s(video):", info);
                    break;
            }
            sprintf(info, "%s[%10s]\n", info, c_temp->name);
        } else {
            sprintf(info, "%sencode:", info);
        }
        c_temp = c_temp->next;
    }
    return env->NewStringUTF(info);
}


}