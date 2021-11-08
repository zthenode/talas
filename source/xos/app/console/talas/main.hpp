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
///   Date: 11/6/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_TALAS_MAIN_HPP
#define XOS_APP_CONSOLE_TALAS_MAIN_HPP

#include "xos/app/console/talas/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace talas {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
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
    maint(): default_run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw xos::exception(exception_unexpected);
    }

protected:
    /// ...run
    int (derives::*default_run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((default_run_)) {
            err = (this->*default_run_)(argc, argv, env);
        } else {
            if (!(err = this->all_version_run(argc, argv, env))) {
                err = this->all_usage(argc, argv, env);
            }
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace talas
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_TALAS_MAIN_HPP 
