#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio.hpp>
#include <iostream>

class Client {
public:
    Client(const std::string& host, int port);
    void connectToServer();
    void sendData(const std::string& data);
    void receiveData();

private:
    std::string host_;
    int port_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
};

#endif
