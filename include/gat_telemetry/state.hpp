# pragma once

# include "lib.hpp"

namespace gat_telemetry {
    enum State : uint8_t {
        STARTUP = 0x00,
        REMOTE_INIT = 0x01,
        LOCAL_INIT = 0x02,

        READY = 0x10,
        LAUNCHING = 011,

        RUNNING = 0x20,

        LANDING = 0x40,
        DONE = 0x50,

        // Error codes
        ERROR = 0x80,
        CRITICAL_ERROR = 0x81
    };

    class StateMachine {
    public:
        /// @brief The current state of the state machine
        State state;

        StateMachine();

        
    };
}