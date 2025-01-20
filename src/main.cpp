#include "network/server.hpp"
#include "network/client.hpp"

int main() {
    int choice;
    std::cout << "Select mode: 1. Server  2. Client\n";
    std::cin >> choice;

    if (choice == 1) {
        Server server(8080);
        server.start();
    } else if (choice == 2) {
        Client client("127.0.0.1", 8080);
        client.connectToServer();
        client.sendData("Hello, server!");
        client.receiveData();
    } else {
        std::cerr << "Invalid choice" << std::endl;
    }

    return 0;
}
