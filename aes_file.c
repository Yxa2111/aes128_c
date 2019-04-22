#include "aes.h"
#include <string.h>
#define min(a,b) ((a < b) ? (a) : (b))

char* passwd_cpy(char *src) {
    int str_len = strlen(src);
    int len = min(str_len,16);
    char* passwd = malloc(sizeof(byte) * 16);
    memcpy(passwd,src,sizeof(byte) * len);
    for(int i = 0; len < 16; i = (i + 1) % str_len) {
        passwd[len++] = src[i];
    }
    return passwd;
}

const char* usage = "uasge:\ndecrypt: ./aes_file 1 input_filename output_filename your_password(len <= 16)\nencrypt: ./aes_file 2 input_filename output_filename your_password(len <= 16)";
int main(int argc,char** argv) {
    if(argc != 5) { puts(usage); return 0; }
    if(strcmp(argv[1],"1") == 0) {
        FILE *fp = fopen(argv[2],"rb");
        FILE *sp = fopen(argv[3],"wb");
        char* passwd = passwd_cpy(argv[4]);
        encode_file(fp,sp,passwd);
        puts("end.");
    } else if(strcmp(argv[1],"2") == 0) {
        FILE *fp = fopen(argv[2],"rb");
        FILE *sp = fopen(argv[3],"wb");
        char* passwd = passwd_cpy(argv[4]);
        if(!decode_file(fp,sp,passwd)) puts("passwd error!"); 
        puts("end.");
    }
    
    return 0;
}