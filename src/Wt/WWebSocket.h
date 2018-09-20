#ifndef WWEBSOCKETHANDLER_
#define WWEBSOCKETHANDLER_

#include <Wt/WObject.h>
#include <Wt/WSignal.h>

namespace Wt {
class WebSocketMessage;

class WT_API WWebSocketConnectionInformation final
{
public:
    std::string internalPath;
};

class WT_API WWebSocket final : public WObject
{
public:
    WWebSocket(WWebSocketConnectionInformation &&);
    WWebSocketConnectionInformation const & getConnectionInformation(void) const;
    /*
     * Signalled when a message arrives from the client web browser.
     */
    Signal<WebSocketMessage &, WWebSocket &> & handleMessageFromClient();
    /*
     * Signalled when the server application wants to send a message to the browser.
     */
    Signal<WebSocketMessage &, WWebSocket &> & handleMessageFromServer();
    /*
     * Call to fire the event announcing a message from the client browser.
     */
    void messageFromClient(WebSocketMessage &);
    /*
     * Call to fire an event to send a message to the client browser.
     */
    void messageToClient(WebSocketMessage &);
private:
    Signal<WebSocketMessage &, WWebSocket &> _handleMessageFromClient;
    Signal<WebSocketMessage &, WWebSocket &> _handleMessageFromServer;
    WWebSocketConnectionInformation _connectionInformation;
};

}
#endif // WWEBSOCKETHANDLER_
