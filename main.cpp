#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <chrono>
#include <thread>

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;

int main() {
    boost::asio::io_context ioc;

    tcp::acceptor acceptor{ioc, {tcp::v4(), 8080}};
    if (!acceptor.is_open()) {
        std::cerr << "Failed to open the acceptor\n";
        return EXIT_FAILURE;
    }

    for (;;) {
        try {
            tcp::socket socket{ioc};
            acceptor.accept(socket);
            std::cerr << "New connection accepted\n";

            http::response<http::string_body> res{http::status::ok, 11};
            res.set(http::field::content_type, "application/json");
            res.body() = "{\"message\": \"Hello from C++ server!\"}";
            res.prepare_payload();

            http::write(socket, res);
            std::cerr << "Message sent: " << res.body() << "\n";

            socket.shutdown(tcp::socket::shutdown_send);
            std::cerr << "Socket closed\n";

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

    }

    return 0;
}
