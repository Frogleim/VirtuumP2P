#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/asio.hpp>
#include <iostream>

class Server {
public:
    Server(int port);
    void start();

private:
    void acceptConnection();
    void handleClient(boost::asio::ip::tcp::socket socket);

    int port_;
    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif
