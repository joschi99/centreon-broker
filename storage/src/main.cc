/*
** Copyright 2011 Merethis
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

#include <QSqlDatabase>
#include "com/centreon/broker/io/protocols.hh"
#include "com/centreon/broker/storage/factory.hh"
#include "com/centreon/broker/storage/stream.hh"

using namespace com::centreon::broker;

// Load count.
static unsigned int instances(0);

extern "C" {
  /**
   *  Module deinitialization routine.
   */
  void broker_module_deinit() {
    // Decrement instance number.
    if (!--instances) {
      // Deregister storage layer.
      io::protocols::instance().unreg("storage");

      // Remove the workaround connection.
      if (QSqlDatabase::contains()) {
        // It is impossible to remove database if the database is
        // already used. So this scope is use to get the connection
        // name and destroy database to remove it after.
        QString connection_name;
        {
          QSqlDatabase db(QSqlDatabase::database());
          connection_name = db.connectionName();
        }
        QSqlDatabase::removeDatabase(connection_name);
      }
    }
    return ;
  }

  /**
   *  Module initialization routine.
   *
   *  @param[in] arg Configuration object.
   */
  void broker_module_init(void const* arg) {
    (void)arg;

    // Increment instance number.
    if (!instances++) {
      // This is a workaround to keep a mysql driver open.
      if (!QSqlDatabase::contains())
        QSqlDatabase::addDatabase("QMYSQL");

      // Register storage layer.
      io::protocols::instance().reg("storage",
        storage::factory(),
        1,
        7);
    }
    return ;
  }
}
