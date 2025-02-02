# pragma once

# include <inttypes.h>

# include "lib.hpp"
# include "state.hpp"

/// Maximum version string length (including null-terminator)
# define VERSION_STRING_LEN 24

namespace gat_telemetry {
    /// The different command IDs 
    enum RemoteRequestID : uint16_t {
        /// @brief Default, errorful request with ID `0`, ensuring that a request ID can only be non-zero to be valid
        Error = 0x0000,

        // Basic commands
        /// @brief Yields basic information about the software
        Info = 0x0100,
        /// @brief Frequently called command that yields state information and more
        Ping = 0x0110,

        // Machine
            /// Performs a soft restart
            Restart = 0x0200,
            /// performs a complete restart
            FirmwareRestart = 0x201,
        // 

        // State Machine
            /// @brief Requests a state change to the core MCU
            StateChange = 0x400,
        // 
    };

    enum ResponseCode {
        /// No errors have araised while proccessing the request
        Success = 0x0000,

        // Command errors
        UnknownCommand = 0x0100
    };

    /// Uniform structure for command responses
    struct RemoteResponse {
        ResponseCode code;

        uint8_t* data;
        size_t data_len; 
    };

    /// Generic definition of a request handling function
    typedef RemoteResponse (*RequestHandler)(char* msg, size_t msg_len);

    namespace request {
        struct StateChange {
            State new_state;
        }; 
    }

    /// Response structures
    namespace response {
        struct Info {
            /// Version string of the core MCU
            const char* core_mcu_version;
            /// Version string of the tradre MCU
            const char* trader_mcu_version;
            /// Version string of the Single-Board-Computer
            const char* sbc_version;
            /// Version string of the telemetry library used
            const char* telemetry_version = TELEMETRY_VERSION;
        };

        struct Ping {
            // Current state of the machine
            State state;

            // TODO: Add position data and more
        }; 
    }
}