#ifndef WWEBSOCKETHANDLER_
#define WWEBSOCKETHANDLER_

#include <Wt/WObject.h>

class WebSocketMessage;

namespace Wt {

class WT_API WWebSocketConnectionInformation final : public WObject
{
    public:
    std::string const & getInternalPath(void) const;
private:
    std::string internalPath;
};

class WWebSocket;

class WT_API WWebSocketConnectionHandler : public WObject
{
    public:
    virtual ~WWebSocketConnectionHandler(){};
    virtual bool acceptConnection(WWebSocketConnectionInformation const &) {return true;};
    virtual void handleConnection(WWebSocket &) {};
};

class WT_API WWebSocket final : public WObject
{
    public:
    WWebSocket(WWebSocketConnectionInformation &&);
    Signal<std::unique_ptr<WebSocketMessage>, WWebSocket &> & handleMessage();
    void sendMessage(WebSocketMessage &) {}
    WWebSocketConnectionInformation const & getConnectionInformation(void) const {return _connectionInformation;}
    private:
    Signal<std::unique_ptr<WebSocketMessage>> _handleMessage;
    WWebSocketConnectionInformation _connectionInformation;
};

}
#endif // WWEBSOCKETHANDLER_
