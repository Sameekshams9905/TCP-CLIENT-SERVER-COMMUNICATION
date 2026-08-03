#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SPORT 60000
#define IPA "172.17.60.25"    // Server IP address

unsigned char a[8] = {1,2,3,4,5,6,7,8};   // fixed: was 9 elements in 8-size array

int main(void) {
    int s, n, m;               // added missing variable declarations
    struct sockaddr_in sa;

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
        exit(0);
    }
    printf("socket id is %d\n", s);

    // Fill sa structure with server side info
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(IPA);  // dotted decimal to 32 bits
    sa.sin_port = htons(SPORT);           // host to network short (16 bits)

    if (connect(s, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        printf("con error\n");
        exit(0);
    }

    n = send(s, a, 8, 0);     // a - array name is buffer address
    printf("%d bytes sent\n", n);

    for (m = 0; m < 8; m++)
        printf("%d\n", a[m]);

    close(s);
    exit(0);
}
