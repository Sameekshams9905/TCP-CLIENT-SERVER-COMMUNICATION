#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define SPORT 60000

int main(void) {
    int s, ct, m, k, bind_r, lv, l;   // fixed garbled variable declaration
    struct sockaddr_in sa, aa;
    unsigned char a[8];

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
        exit(0);
    }
    printf("socket id is %d\n", s);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;   // server listens on all interfaces
    sa.sin_port = htons(SPORT);

    bind_r = bind(s, (struct sockaddr *)&sa, sizeof(sa));
    printf("bind result = %d\n", bind_r);

    lv = listen(s, 5);
    l = sizeof(aa);
    printf("waiting...\n");

    if ((ct = accept(s, (struct sockaddr *)&aa, &l)) < 0) {  // fixed == to =
        printf("error\n");
        exit(0);
    }
    printf("connection done\n");

    m = recv(ct, a, 8, 0);    // fixed recvfrom to recv (TCP uses recv)
    printf("%d bytes received\n", m);

    for (k = 0; k < 8; k++)
        printf("%d\n", a[k]);

    close(s);
    return 0;
}
