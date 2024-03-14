#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_no_tls_client.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client;

void WebSocketSend(void) {
    printf("DEBUG. WebSocketSend Started. \n");
    //// Create a WebSocketPP client endpoint
    //client c;

    //// Bind the callback functions
    //c.set_message_handler([](websocketpp::connection_hdl hdl, client::message_ptr msg) {
    //    // Print received message
    //    std::cout << "Received message: " << msg->get_payload() << std::endl;
    //    });

    //// Connect to the WebSocket server
    //websocketpp::lib::error_code ec;
    //client::connection_ptr con = c.get_connection("ws://localhost:9002", ec);
    //if (ec) {
    //    std::cout << "Could not create connection: " << ec.message() << std::endl;
    //    return -1;
    //}

    //c.connect(con);

    //// Send a message
    //std::string message = "Hello, world!";
    //c.send(con->get_handle(), message, websocketpp::frame::opcode::text, ec);
    //if (ec) {
    //    std::cout << "Error sending message: " << ec.message() << std::endl;
    //    return -1;
    //}

    //// Run the WebSocket event loop
    //c.run();

    //return 0;
}