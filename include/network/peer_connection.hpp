#ifndef PEER_CONNECTION_HPP
#define PEER_CONNECTION_HPP

#include <boost/asio.hpp>
#include <iostream>
#include <string>

class PeerConnection {
public:
    PeerConnection(const std::string& host, int port);
    bool connect();
    void sendMessage(const std::string& message);
    std::string receiveMessage();
    void close();

private:
    std::string host_;
    int port_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
};

#endif
