#include "network/peer_connection.hpp"

PeerConnection::PeerConnection(const std::string& host, int port)
    : host_(host), port_(port), socket_(io_context_) {}

bool PeerConnection::connect() {
    try {
        boost::asio::ip::tcp::resolver resolver(io_context_);
        boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host_, std::to_string(port_));
        boost::asio::connect(socket_, endpoints);
        return true;
    } catch (std::exception& e) {
        std::cerr << "Connection failed: " << e.what() << std::endl;
        return false;
    }
}

void PeerConnection::sendMessage(const std::string& message) {
    boost::asio::write(socket_, boost::asio::buffer(message));
}

std::string PeerConnection::receiveMessage() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket_, buffer, "\n");
    std::istream is(&buffer);
    std::string received_data;
    std::getline(is, received_data);
    return received_data;
}

void PeerConnection::close() {
    socket_.close();
}
