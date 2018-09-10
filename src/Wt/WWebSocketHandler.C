#include <WWebSocketHandler.h>

namespace Wt {
Signal<std::unique_ptr<WebSocketMessage>> & WWebSocketHandler::handleMessage(void)
{
    return _handleMessage;
}
}
