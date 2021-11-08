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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 11/8/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPT_HPP

#include "xos/app/console/network/sockets/base/main.hpp"
#include "xos/app/console/network/server/main_opt.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_NETWORK_SERVER_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_NETWORK_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace server {

/// class main_optt
template 
<class TExtends = network::server::main_optt<network::sockets::base::maint<> >, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0), accept_ep_(0), accept_tp_(0), relay_ep_(0), relay_tp_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
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
    virtual int accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accept_restart = false;
        do {
            this->set_accept_done(false);
            if (!(err = this->all_accept(argc, argv, env))) {
                if (!(this->accept_once())) {
                    accept_restart = this->accept_restart();
                }
                this->set_accept_restart(false);
            }
        } while (accept_restart);
        return err;
    }

    /// accept
    /// ...
    /// ...accept
    virtual int accept(int argc, char_t** argv, char_t**env) {
        const xos::network::sockets::sockstring_t& host = this->accept_host();
        const xos::network::sockets::sockport_t& port = this->accept_port();
        xos::network::sockets::endpoint& ep = this->accept_ep();
        xos::network::sockets::transport& tp = this->accept_tp();
        xos::network::sockets::interface &ac = this->accept_iface(), 
                                         &cn = this->connect_iface();
        xos::network::sockets::sockaddr_t& ad = this->connect_addr();
        xos::network::sockets::socklen_t& al = this->connect_addrlen();
        int err = 0;

        if ((ep.attach(host, port))) {

            if ((ac.open(tp))) {
                
                if ((ac.listen(ep))) {
                    
                    do {
                        if ((ac.accept(cn, &ad, al))) {
                            
                            this->all_accept(cn, argc, argv, env);
                            cn.close();
                        }
                    } while (!(this->accept_once() || this->accept_done() || this->accept_restart()));
                }
                ac.close();
            }
            ep.detach();
        }
        return err;
    }
    virtual int before_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(argc, argv, env))) {
            int err2 = 0;
            err = accept(argc, argv, env);
            if ((err2 = after_accept(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...accept
    virtual int accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_recv_request(cn, argc, argv, env))) {
            err = this->all_send_response(cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(cn, argc, argv, env))) {
            int err2 = 0;
            err = accept(cn, argc, argv, env);
            if ((err2 = after_accept(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// accept

    /// relay
    /// ...
    /// ...relay
    virtual int relay(int argc, char_t** argv, char_t** env) {
        const xos::network::sockets::sockstring_t& host = this->relay_host();
        const xos::network::sockets::sockport_t& port = this->relay_port();
        xos::network::sockets::endpoint& ep = this->relay_ep();
        xos::network::sockets::transport& tp = this->relay_tp();
        xos::network::sockets::interface &cn = this->relay_iface();
        int err = 0;
        if ((ep.attach(host, port))) {

            if ((cn.open(tp))) {
                
                if ((cn.connect(ep))) {
                    
                    this->all_relay(cn, argc, argv, env);
                }
                cn.close();
            }
            ep.detach();
        }
        return err;
    }
    virtual int before_relay(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay(argc, argv, env))) {
            int err2 = 0;
            err = relay(argc, argv, env);
            if ((err2 = after_relay(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...relay
    virtual int relay(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_relay_request(cn, argc, argv, env))) {
            err = this->all_relay_response(cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_relay(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay(cn, argc, argv, env))) {
            int err2 = 0;
            err = relay(cn, argc, argv, env);
            if ((err2 = after_relay(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// relay

    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...ep
    xos::network::sockets::endpoint& (derives::*relay_ep_)() const;
    virtual xos::network::sockets::endpoint& relay_ep() const {
        if ((this->relay_ep_)) {
            return (this->*relay_ep_)();
        }
        return this->default_relay_ep();
    }
    virtual xos::network::sockets::endpoint& default_relay_ep() const {
        return this->relay_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& relay_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& relay_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*relay_tp_)() const;
    virtual xos::network::sockets::transport& relay_tp() const {
        if ((this->relay_tp_)) {
            return (this->*relay_tp_)();
        }
        return this->default_relay_tp();
    }
    virtual xos::network::sockets::transport& default_relay_tp() const {
        return this->relay_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& relay_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& relay_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...host / ...port
    virtual const string_t& get_host() const {
        return this->accept_host();
    }
    virtual const short& get_port() const {
        return this->accept_port();
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_OPT_HPP
