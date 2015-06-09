/*
** Copyright 2011-2012,2015 Merethis
**
** This file is part of Centreon Broker.
**
** Centreon Broker is free software: you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2
** as published by the Free Software Foundation.
**
** Centreon Broker is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Centreon Broker. If not, see
** <http://www.gnu.org/licenses/>.
*/

#ifndef CCB_CONFIG_STATE_HH
#  define CCB_CONFIG_STATE_HH

#  include <list>
#  include <map>
#  include <string>
#  include "com/centreon/broker/config/endpoint.hh"
#  include "com/centreon/broker/config/logger.hh"
#  include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace                         config {
  /**
   *  @class state state.hh "com/centreon/broker/config/state.hh"
   *  @brief Full configuration state.
   *
   *  A fully parsed configuration is represented within this class
   *  which holds mandatory parameters as well as optional parameters,
   *  along with object definitions.
   */
  class                           state {
  public:
                                  state();
                                  state(state const& other);
                                  ~state();
    state&                        operator=(state const& other);
    void                          cache_directory(std::string const& dir);
    std::string const&            cache_directory() const throw ();
    void                          command_file(std::string const& file);
    std::string const&            command_file() const throw();
    void                          clear();
    std::list<endpoint>&          endpoints() throw ();
    std::list<endpoint> const&    endpoints() const throw ();
    void                          event_queue_max_size(
                                    unsigned int val) throw ();
    unsigned int                  event_queue_max_size() const throw ();
    void                          flush_logs(bool flush) throw ();
    bool                          flush_logs() const throw ();
    void                          instance_id(unsigned int id) throw ();
    unsigned int                  instance_id() const throw ();
    void                          instance_name(
                                    std::string const& name) throw ();
    std::string const&            instance_name() const throw ();
    void                          log_thread_id(bool log_id) throw ();
    bool                          log_thread_id() const throw ();
    void                          log_timestamp(bool log_time) throw ();
    bool                          log_timestamp() const throw ();
    void                          log_human_readable_timestamp(
                                    bool human_log_time) throw ();
    bool                          log_human_readable_timestamp() const throw();
    std::list<logger>&            loggers() throw ();
    std::list<logger> const&      loggers() const throw ();
    std::string const&            module_directory() const throw ();
    void                          module_directory(
                                    std::string const& dir);
    std::list<std::string>&       module_list() throw ();
    std::list<std::string> const& module_list() const throw ();
    std::map<std::string, std::string>&
                                  params() throw ();
    std::map<std::string, std::string> const&
                                  params() const throw ();

  private:
    void                          _internal_copy(state const& other);

    std::string                   _cache_directory;
    std::string                   _command_file;
    std::list<endpoint>           _endpoints;
    unsigned int                  _event_queue_max_size;
    bool                          _flush_logs;
    unsigned int                  _instance_id;
    std::string                   _instance_name;
    bool                          _log_thread_id;
    bool                          _log_timestamp;
    bool                          _log_human_readable_timestamp;
    std::list<logger>             _loggers;
    std::string                   _module_dir;
    std::list<std::string>        _module_list;
    std::map<std::string, std::string>
                                  _params;
  };
}

CCB_END()

#endif // !CCB_CONFIG_STATE_HH
