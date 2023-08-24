#include <winsock2.h>

namespace sock
{
  SOCKET client;
  void start()
  {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    client = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(4567);

    if (connect(client, reinterpret_cast<sockaddr *>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR)
    {
      MessageBoxA(NULL, "Erreur de connection", "Erreur", MB_OK);
      closesocket(client);
      WSACleanup();
    }
  }
  void sendSignal(const char *signal)
  {
    if (send(client, signal, strlen(signal), 0) == SOCKET_ERROR)
    {
      MessageBoxA(NULL, "Erreur d'envoi du signal", "Erreur", MB_OK);
    }
  }
  void stop()
  {
    closesocket(client);
    WSACleanup();
  }
}
