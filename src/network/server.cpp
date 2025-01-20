#include "network/server.hpp"
#include "network/logger.hpp"



Server::Server(int port)
    : port_(port),
      acceptor_(io_context_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port_)) {}



void Server::start() {
    Logger logger("logs");
    
    
    std::cout << "Server is running on port " << port_ << std::endl;
    std::string message = "Server is running on port " + std::to_string(port_);
    logger.log(INFO_LEVEL, message);

    acceptConnection();
    io_context_.run();
}

void Server::acceptConnection() {
    Logger logger("logs");

    auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context_);
    logger.log(INFO_LEVEL, "Socket information");
    acceptor_.async_accept(*socket, [this, socket](boost::system::error_code ec) {
        if (!ec) {
            std::cout << "New connection established." << std::endl;
            handleClient(std::move(*socket));
        } else {
            std::cerr << "Accept error: " << ec.message() << std::endl;
        }
        acceptConnection();  // Continue accepting more connections
    });
}
void Server::handleClient(boost::asio::ip::tcp::socket socket) {
    std::string message = "Welcome to Virtuum P2P Node!\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}
