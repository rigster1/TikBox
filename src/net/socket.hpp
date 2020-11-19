/*
 * wlpp Copyright 2020 Max Burns
 * See LICENSE for more information.
 *
 * Created by chez4 19/11/20
 */

#ifndef TIKBOX_SOCKET_HPP
#define TIKBOX_SOCKET_HPP

#include <string>

#include <cstdint>

#include <arpa/inet.h>
#include <sys/socket.h>

namespace tkb {

class socket {
private:
    int sockfd;

    sockaddr_in ipv4;

public:
    socket(const std::string &, std::uint16_t);

    ~socket();

    socket(const socket &) = delete;

    socket(socket &&) noexcept;

    socket &operator=(socket);

    friend void swap(socket &, socket &);

    void bind() const;

    void connect() const;
};

}

#endif
