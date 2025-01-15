# pragma once

# include <inttypes.h>

namespace gat_telemetry {
    enum RemoteRequestID : uint16_t {
        /// @brief Default, errorful request with ID `0`, ensuring that a request ID can only be non-zero to be valid
        ERROR = 0x0000,

        INFO = 0x0100,

        // State

        // 
    };

    enum ResponseCode {
        NONE = 0x0000
    };

    struct RemoteResponse {
        ResponseCode code;
    };

    typedef RemoteResponse (*RequestHandler)(char* msg, size_t msg_len);
}