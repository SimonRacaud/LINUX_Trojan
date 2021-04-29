/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 main.c
*/

#include "client.h"

const char IP[] = "127.0.0.1";
const int PORT = 42;

bool loop = true;

static int init(int *fd, uint port, const char *ip)
{
    struct sockaddr_in data = {0};
    int ret;

    *fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    data.sin_family = AF_INET;
    data.sin_port = htons(port);
    ret = inet_pton(AF_INET, ip, &data.sin_addr);
    if (ret == -1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    ret = connect(*fd, (struct sockaddr *) &data, sizeof(data));
    if (ret == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static void signal_handler(__attribute__((unused))int signo)
{
    printf("CTRL+C exit\n");
    loop = false;
}

static void prompt(int fd)
{
    char buffer[1024] = {0};
    ssize_t nb;

    printf("$> ");
    fflush(stdout);
    nb = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (nb == -1 || nb == 0)
        return;
    buffer[nb] = '\0';
    if (send(fd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(errno);
    }
}

int main(int argc, char **argv)
{
    int sock_fd = -1;

    if (init(&sock_fd, PORT, IP) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (reader_start(sock_fd) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (signal(SIGINT, &signal_handler) == SIG_ERR  )
        return EXIT_FAILURE;
    while (loop) {
        prompt(sock_fd);
    }
    return EXIT_SUCCESS;
}
