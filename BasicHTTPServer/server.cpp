#include <unistd.h> // close()
#include <sys/socket.h> // socket(), bind(), listen(), accept()
#include <netinet/in.h> // sockaddr_in
#include <iostream>

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        std::cerr << "Socket failed\n";
        return -1;
    }
    
    // 2. Attach socket to port 8080
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Bind failed\n";
        return -1;
    }
    
    // 3. Start listening
    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Listen failed\n";
        return -1;
    }
    
    std::cout << "Server listening on port 8080…\n";

    // 4. Accept one connection
    int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket < 0)
    {
        std::cerr << "Accept failed\n";
        return -1;
    }
    std::cout << "Client Connected!\n New client is " << new_socket << std::endl;

    // 5. Read data from client
    char buffer[1024] = {0};
    int bytes = read(new_socket, buffer, 1024);

    std::cout << "Received:\n" << buffer << std::endl;
    std::cout << "Received Bytes size is:" << bytes << std::endl;

    // HTTP response
const char* response =
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 48\r\n"
"\r\n"
"Hello World";

    // Send response back from the same socket
    send(new_socket, response, strlen(response), 0);
    std::cout << "Response sent!\n";
    // 6. Close sockets
    close(new_socket);
    close(server_fd);
}