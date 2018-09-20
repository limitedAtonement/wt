#include <Wt/WWebSocket.h>
#include <Wt/WSignal.h>

namespace Wt {
WWebSocket::WWebSocket(WWebSocketConnectionInformation && info)
    : _connectionInformation{std::move(info)}
{
}

Signal<WebSocketMessage &, WWebSocket &> & WWebSocket::handleMessageFromClient(void)
{
    return _handleMessageFromClient;
}

WWebSocketConnectionInformation const & WWebSocket::getConnectionInformation(void) const
{
    return _connectionInformation;
}

void WWebSocket::messageFromClient(WebSocketMessage & message)
{
    _handleMessageFromClient.emit(message, *this);
}

}

