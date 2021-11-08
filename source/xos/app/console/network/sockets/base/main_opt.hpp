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
///   Date: 11/7/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP

#include "xos/app/console/rete/version/main.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE "Hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT "relay-host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE "Relay hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C 's'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT "relay-port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE "Relay port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S "t::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C 't'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERSION_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV 0,

#if !defined(WINSOCK_1)
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::rete::version::main, 
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
    main_optt(): run_(0), default_run_(0) {
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
    int (derives::*default_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((default_run_)) {
            err = (this->*default_run_)(argc, argv, env);
        } else {
            err = extends::default_run(argc, argv, env);
        }
        return err;
    }

    /// ...host_run
    virtual int host_run(int argc, char_t** argv, char_t** env) {
        const string_t& host = this->get_host();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_host_run(argc, argv, env))) {
            int err2 = 0;
            err = host_run(argc, argv, env);
            if ((err2 = after_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_host_run;
        return err;
    }
    virtual int before_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_host_run(argc, argv, env))) {
            int err2 = 0;
            err = set_host_run(argc, argv, env);
            if ((err2 = after_set_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...port_run
    virtual int port_run(int argc, char_t** argv, char_t** env) {
        const short& port = this->get_port();
        int err = 0;
        if (0 < (port)) {
            this->outln(unsigned_to_string(port).chars());
        }
        return err;
    }
    virtual int before_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_port_run(argc, argv, env))) {
            int err2 = 0;
            err = port_run(argc, argv, env);
            if ((err2 = after_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_port_run;
        return err;
    }
    virtual int before_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_port_run(argc, argv, env))) {
            int err2 = 0;
            err = set_port_run(argc, argv, env);
            if ((err2 = after_set_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...relay_host_run
    virtual int relay_host_run(int argc, char_t** argv, char_t** env) {
        const string_t& relay_host = this->relay_host();
        const char_t* chars = 0; size_t length = 0;
        int err = 0;
        if ((chars = relay_host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_host_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_host_run(argc, argv, env);
            if ((err2 = after_relay_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_host_run;
        return err;
    }
    virtual int before_set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_relay_host_run(argc, argv, env))) {
            int err2 = 0;
            err = set_relay_host_run(argc, argv, env);
            if ((err2 = after_set_relay_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...relay_port_run
    virtual int relay_port_run(int argc, char_t** argv, char_t** env) {
        const short& relay_port = this->get_relay_port();
        int err = 0;
        if (0 < (relay_port)) {
            this->outln(unsigned_to_string(relay_port).chars());
        }
        return err;
    }
    virtual int before_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_port_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_port_run(argc, argv, env);
            if ((err2 = after_relay_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_port_run;
        return err;
    }
    virtual int before_set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_relay_port_run(argc, argv, env))) {
            int err2 = 0;
            err = set_relay_port_run(argc, argv, env);
            if ((err2 = after_set_relay_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        string_t& host = this->host();
        const char_t* chars = to.has_chars();
        if ((chars)) host.assign(to);
        else host.clear();
        return host;
    }
    virtual const string_t& get_host() const {
        return host();
    }
    virtual string_t& host() const {
        static string_t host(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST);
        return host;
    }
    virtual short& set_port(short to) {
        short& port = this->port();
        port = to;
        return port;
    }
    virtual const short& get_port() const {
        const short& port = this->port();
        return port;
    }
    virtual short& port() const {
        static short port = XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT;
        return port;
    }

    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        string_t& relay_host = this->relay_host();
        const char_t* chars = to.has_chars();
        if ((chars)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual string_t& relay_host() const {
        static string_t relay_host(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST);
        return relay_host;
    }
    virtual short& set_relay_port(short to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual const short& get_relay_port() const {
        const short& relay_port = this->relay_port();
        return relay_port;
    }
    virtual short& relay_port() const {
        static short relay_port = XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT;
        return relay_port;
    }

    /// ...option...
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_host(optarg);
        } else {
            err = this->all_set_host_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG;
        return chars;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned port = arg.to_unsigned();
            if ((0 < port)) {
                this->set_port(port);
            }
        } else {
            err = this->all_set_port_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG;
        return chars;
    }
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_relay_host(optarg);
        } else {
            err = this->all_set_relay_host_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* relay_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG;
        return chars;
    }
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned relay_port = arg.to_unsigned();
            if ((0 < relay_port)) {
                this->set_relay_port(relay_port);
            }
        } else {
            err = this->all_set_relay_port_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* relay_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            chars = relay_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            chars = relay_port_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
