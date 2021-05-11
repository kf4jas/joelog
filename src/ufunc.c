#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>

const char *homedir;

void load_homedir(){
    homedir = getenv("HOME");
    if (homedir == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    printf("%s",homedir);
}

int main(){
  printf("%s",homedir);
}
