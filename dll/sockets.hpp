#include <winsock2.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>

namespace sock
{
  std::vector<std::string> msgList;

  SOCKET server;
  bool exit = false;
  bool toggleAC = false;
  bool toggleFP = false;
  bool toggleAS = false;

  void handleConnection(SOCKET clientSocket, const sockaddr_in &clientAddress)
  {
    std::cout << "New connection from: " << inet_ntoa(clientAddress.sin_addr) << std::endl;

    char buffer[4096];
    int bytesRead;
    while (true)
    {
      bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
      if (bytesRead <= 0)
      {
        // Error or connection closed by the client
        break;
      }

      std::cout << "Recu un message de " << inet_ntoa(clientAddress.sin_addr) << ": ";
      std::cout.write(buffer, bytesRead);
      std::cout << std::endl;

      std::string message = std::string(buffer);

      if (message.contains("stop"))
      {
        break;
      }
      if (message.contains("ac"))
      {
        toggleAC = !toggleAC;
      }
      if (message.contains("as"))
      {
        toggleAS = !toggleAS;
      }
      if (message.contains("fp"))
      {
        toggleFP = !toggleFP;
      }
    }
    exit = true;

    closesocket(clientSocket);
    std::cout << "Connection closed with: " << inet_ntoa(clientAddress.sin_addr) << std::endl;
  }

  void startServer()
  {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == INVALID_SOCKET)
    {
      std::cerr << "Failed to create socket." << std::endl;
      WSACleanup();
      return;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Listen on localhost
    serverAddress.sin_port = htons(4567);

    if (bind(server, reinterpret_cast<sockaddr *>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR)
    {
      std::cerr << "Failed to bind socket to port." << std::endl;
      closesocket(server);
      WSACleanup();
      return;
    }

    listen(server, SOMAXCONN);

    std::cout << "Server is listening for connections on port 4567..." << std::endl;

    sockaddr_in clientAddress{};
    int clientAddressSize = sizeof(clientAddress);

    SOCKET clientSocket = accept(server, reinterpret_cast<sockaddr *>(&clientAddress), &clientAddressSize);

    std::thread connectionThread(handleConnection, clientSocket, clientAddress);
    connectionThread.detach();
  }

  void close()
  {
    closesocket(server);
    WSACleanup();
  }
}