#include "network/client.hpp"

Client::Client(const std::string& host, int port)
    : host_(host), port_(port), socket_(io_context_) {}

void Client::connectToServer() {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host_, std::to_string(port_));
    boost::asio::connect(socket_, endpoints);
    std::cout << "Connected to server." << std::endl;
}

void Client::sendData(const std::string& data) {
    boost::asio::write(socket_, boost::asio::buffer(data + "\n"));
}

void Client::receiveData() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket_, buffer, "\n");

    // Option 1: Using std::istream (Recommended)
    std::istream is(&buffer);
    std::string received_data;
    std::getline(is, received_data);

    std::cout << "Received: " << received_data << std::endl;
}
