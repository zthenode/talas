///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 11/7/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP

#include "xos/app/console/network/sockets/client/main_opt.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_METHOD "GET"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_PATH "/"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT "Get\r\n"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT_LENGTH "5"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT_LENGTH_HEADER \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_LENGTH_HEADER_NAME \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_HEADER_NAME_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT_LENGTH 

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_LINE \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_METHOD \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_LINE_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_PATH \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_LINE_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PROTOCOL \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PART_SEPARATOR
    
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_HEADERS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PART_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT_LENGTH_HEADER \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PART_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PART_SEPARATOR
    
namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace client {

/// class maint
template 
<class TExtends = network::sockets::client::main_optt<>, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0), connect_request_
      (XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_LINE
       XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_HEADERS
       XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_REQUEST_MESSAGE_CONTENT) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        string_t& connect_request = this->connect_request();
        int err = 0;
        err = this->all_send_request(cn, connect_request, argc, argv, env);
        return err;
    }

    /// ...recv_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        string_t& connect_response = this->connect_response();
        int err = 0;
        err = this->all_recv_response(connect_response, cn, argc, argv, env);
        return err;
    }

    /// connect request / response
    virtual string_t& connect_request() const {
        return (string_t&)connect_request_;
    }
    virtual string_t& connect_response() const {
        return (string_t&)connect_response_;
    }

protected:
    string_t connect_request_, connect_response_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_HPP
