/*
 * wlpp Copyright 2020 Max Burns
 * See LICENSE for more information.
 *
 * Created by chez4 19/11/20
 */

#include <net/socket.hpp>

#include <utility>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

namespace tkb {

socket::socket(const std::string &address, std::uint16_t port)
    : sockfd(::socket(AF_INET, SOCK_STREAM, 0))
    , ipv4()
{
    ipv4.sin_family = AF_INET;
    ipv4.sin_port = htons(port);
    inet_pton(AF_INET, address.c_str(), &ipv4.sin_addr);
}

socket::~socket()
{
    if (sockfd != -1) {
        shutdown(sockfd, SHUT_RDWR);
        close(sockfd);
    }
}

socket::socket(socket &&other) noexcept
    : sockfd(other.sockfd)
{
    other.sockfd = -1;
}

socket &socket::operator=(socket other)
{
    if (this != &other) swap(*this, other);
    return *this;
}

void swap(socket &a, socket &b)
{
    std::swap(a.sockfd, b.sockfd);
}

void socket::bind() const
{
    ::bind(sockfd, reinterpret_cast<const sockaddr *>(&ipv4), sizeof ipv4);
}

void socket::connect() const
{
    ::connect(sockfd, reinterpret_cast<const sockaddr *>(&ipv4), sizeof ipv4);
}

}
