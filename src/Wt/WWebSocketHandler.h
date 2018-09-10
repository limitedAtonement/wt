#ifndef WWEBSOCKETHANDLER_
#define WWEBSOCKETHANDLER_

#include <web/WebSocketMessage.h>

namespace Wt {

class WWebSocketHandler;

class WT_API WWebSocketHandlerCreator : public WObject
{
    virtual std::unique_ptr<WWebSocketHandler> createWebSocketHandler(void) = 0;
};

class WT_API WWebSocketHandler : public WObject
{
    Signal<std::unique_ptr<WebSocketMessage>> & handleMessage();
    virtual void sendMessage() {}

    private:
    Signal<std::unique_ptr<WebSocketMessage>> _handleMessage;
};

}
#endif // WWEBSOCKETHANDLER_
