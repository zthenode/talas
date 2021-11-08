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
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/base/main_opt.hpp"

#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_LINE_SEPARATOR " "
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PART_SEPARATOR "\r\n"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_HEADER_NAME_SEPARATOR ": "

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_PROTOCOL "HTTP/1.0"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER_NAME "Content-Type"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER_VALUE "text/plain"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER_NAME \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_HEADER_NAME_SEPARATOR \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_TYPE_HEADER_VALUE

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MESSAGE_CONTENT_LENGTH_HEADER_NAME "Content-Length"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class maint
template 
<class TExtends = main_opt, 
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
    : run_(0), sockets_run_(0), 
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      relay_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT) {
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

    /// ...sockets_run
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((sockets_run_)) {
            err = (this->*sockets_run_)(argc, argv, env);
        } else {
            err = this->default_sockets_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// request
    /// ...
    /// ...send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, argc, argv, env);
            if ((err2 = after_send_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_request
    virtual int recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_recv_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request(cn, argc, argv, env);
            if ((err2 = after_recv_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...relay_request
    virtual int relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = relay_request(cn, argc, argv, env);
            if ((err2 = after_relay_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// request

    /// response
    /// ...
    /// ...send_response
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_response(cn, argc, argv, env);
            if ((err2 = after_send_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_recv_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response(cn, argc, argv, env);
            if ((err2 = after_recv_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...relay_response
    virtual int relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = relay_response(cn, argc, argv, env);
            if ((err2 = after_relay_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// response

    /// request
    /// ...
    /// ...send_request
    virtual int send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, request, argc, argv, env);
            if ((err2 = after_send_request(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_request
    virtual int recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        if (!(err = this->recv_crlf2(request, c, cn, argc, argv, env))) {
            err = all_process_request(request, cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request(request, cn, argc, argv, env);
            if ((err2 = after_recv_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// request

    /// response
    /// ...
    /// ...send_response
    virtual int send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    virtual int before_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = send_response(cn, response, argc, argv, env);
            if ((err2 = after_send_response(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_response
    virtual int recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        if (!(err = this->recv_crlf2(response, c, cn, argc, argv, env))) {
            err = all_process_response(response, cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response(response, cn, argc, argv, env);
            if ((err2 = after_recv_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// response

    /// request
    /// ...
    /// ...process_request
    virtual int process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_request(request, cn, argc, argv, env);
            if ((err2 = after_process_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// request

    /// response
    /// ...
    /// ...process_response
    virtual int process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_response(response, cn, argc, argv, env);
            if ((err2 = after_process_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// response

    /// send
    /// ...
    /// send_lf...
    /// ...<lf>
    virtual int send_lf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t lf_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        lf_s.appendlf();
        if ((chars = lf_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// send_cr...
    /// ...<cr>
    virtual int send_cr(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int send_crlf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        cr_s.appendlf();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...
    /// send

    /// recv
    /// ...
    /// recv_lf...
    /// ...<lf>
    virtual int recv_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\n':
                return err = 0;
            }
        }
        return err;
    }
    /// recv_cr...
    /// ...<cr>
    virtual int recv_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                return err = 0;
            }
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int recv_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case cr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                case lf:
                    s = lfcr;
                    break;
                case lfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                case lf:
                    s = ch;
                    break;
                case cr:
                    s = lf;
                    break;
                case lfcr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// <d>[1..n]...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sizeof_sized_crlf2(size_t size_of, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;

        for (size_t remain = size_of; remain; --remain) {
            if  (1 > (amount = cn.recv(&c, 1))) {
                return err;
            }
            r.append(&c, 1);
            size = (size << 8) | ((uint8_t)c);
        }
        err = recv_sized_crlf2(size, r, c, cn, argc, argv, env);
        return err;
    }
    /// ...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sized_crlf2(size_t size, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;
        for (; size; --size) {
            if (1 > (amount = cn.recv(&c, 1))) {
                break;
            } else {
                r.append(&c, 1);
                switch (c) {
                case '\r':
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        break;
                    case lf:
                        s = lfcr;
                        break;
                    case lfcr:
                        s = cr;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                case '\n':
                    switch (s) {
                    case ch:
                        s = ch;
                        break;
                    case cr:
                        s = lf;
                        break;
                    case lf:
                        s = ch;
                        break;
                    case lfcr:
                        return err = 0;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    s = ch;
                    break;
                }
            }
        }
        return err;
    }
    /// ...
    /// recv

    /// host / port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short& set_port(short to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }

    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(short to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }

    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(short to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }

    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(short to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }

    /// ...os_iface
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }

    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }

    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }

    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

protected:
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;

    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
 
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
