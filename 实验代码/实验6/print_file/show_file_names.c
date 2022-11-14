#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

void show_file_names(char[]);

int main(int argc, char** argv)
{
    if(argc == 1){//查看当前目录
        show_file_names(".");
    }else{
        while(--argc){//查看指定的一个或多个目录
            printf("%s : \n", * ++argv);//打印当前所查看的目录路径
            show_file_names(*argv);
        }
    }
}

void show_file_names(char dirname[])
{
    DIR *dir_ptr;//文件夹指针
    struct dirent *direntp;//存放文件夹目录内容

    if((dir_ptr = opendir(dirname)) == NULL){//open环节
        fprintf(stderr, "ls1: open error %s\n",dirname);
    }else{
        while((direntp = readdir(dir_ptr)) != NULL)
            printf("%s\n",direntp -> d_name);
        }
        int flag;
        if(( flag = closedir(dir_ptr)) == -1){//close环节
            perror("ls1: close dir error");
            exit(0);
        }
 }
}

