#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <unistd.h>

int common_thread() {
    sleep(3);
    printf("hello world\n");
    return 0;
}

int main(int argc, char *argv[]) {
    std::thread t(common_thread);
    for (int i = 0; i < 10; i++) {
        printf("main\n");
        sleep(1);
    }
    t.join();
    return 0;
}


