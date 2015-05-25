/*
** Copyright 2009-2013,2015 Merethis
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

#include "com/centreon/broker/io/events.hh"
#include "com/centreon/broker/neb/acknowledgement.hh"
#include "com/centreon/broker/neb/internal.hh"

using namespace com::centreon::broker;
using namespace com::centreon::broker::neb;

/**************************************
*                                     *
*           Public Methods            *
*                                     *
**************************************/

/**
 *  @brief acknowledgement default constructor.
 *
 *  acknowledgement default constructor. Set all members to their
 *  default value (0, NULL or equivalent).
 */
acknowledgement::acknowledgement()
  : acknowledgement_type(0),
    deletion_time(0),
    entry_time(0),
    host_id(0),
    is_sticky(false),
    notify_contacts(false),
    notify_only_if_not_already_acknowledged(false),
    persistent_comment(false),
    service_id(0),
    state(0) {}

/**
 *  @brief acknowledgement copy constructor.
 *
 *  Copy data from the acknowledgement object to the current instance.
 *
 *  @param[in] other  Object to copy.
 */
acknowledgement::acknowledgement(acknowledgement const& other)
  : io::data(other) {
  _internal_copy(other);
}

/**
 *  Destructor.
 */
acknowledgement::~acknowledgement() {}

/**
 *  Assignment operator.
 *
 *  @param[in] other  Object to copy.
 *
 *  @return This object.
 */
acknowledgement& acknowledgement::operator=(acknowledgement const& other) {
  io::data::operator=(other);
  _internal_copy(other);
  return (*this);
}

/**
 *  @brief Get the type of the event.
 *
 *  Return the type of this event. This can be useful for runtime data
 *  type determination.
 *
 *  @return The event type.
 */
unsigned int acknowledgement::type() const {
  return (acknowledgement::static_type());
}

/**************************************
*                                     *
*          Private Methods            *
*                                     *
**************************************/

/**
 *  @brief Copy internal data of the given object to the current
 *         instance.
 *
 *  This internal method is used to copy data defined inside the
 *  acknowledgement class from an object to the current instance. This
 *  means that no superclass data are copied. This method is used in
 *  acknowledgement copy constructor and in the assignment operator.
 *
 *  @param[in] other  Object to copy.
 *
 *  @see acknowledgement(acknowledgement const&)
 *  @see operator=(acknowledgement const&)
 */
void acknowledgement::_internal_copy(acknowledgement const& other) {
  acknowledgement_type = other.acknowledgement_type;
  author = other.author;
  comment = other.comment;
  deletion_time = other.deletion_time;
  entry_time = other.entry_time;
  host_id = other.host_id;
  is_sticky = other.is_sticky;
  notify_contacts = other.notify_contacts;
  notify_only_if_not_already_acknowledged
    = other.notify_only_if_not_already_acknowledged;
  persistent_comment = other.persistent_comment;
  service_id = other.service_id;
  state = other.state;
  return ;
}

/**************************************
*                                     *
*           Static Objects            *
*                                     *
**************************************/

// Mapping.
mapping::entry const acknowledgement::entries[] = {
  mapping::entry(
    &acknowledgement::acknowledgement_type,
    "type"),
  mapping::entry(
    &acknowledgement::author,
    "author"),
  mapping::entry(
    &acknowledgement::comment,
    "comment_data"),
  mapping::entry(
    &acknowledgement::deletion_time,
    "deletion_time",
    mapping::entry::invalid_on_minus_one),
  mapping::entry(
    &acknowledgement::entry_time,
    "entry_time",
    mapping::entry::invalid_on_minus_one),
  mapping::entry(
    &acknowledgement::host_id,
    "host_id",
    mapping::entry::invalid_on_zero),
  mapping::entry(
    &acknowledgement::source_id,
    "instance_id",
    mapping::entry::invalid_on_zero),
  mapping::entry(
    &acknowledgement::is_sticky,
    "sticky"),
  mapping::entry(
    &acknowledgement::notify_contacts,
    "notify_contacts"),
  mapping::entry(
    &acknowledgement::persistent_comment,
    "persistent_comment"),
  mapping::entry(
    &acknowledgement::service_id,
    "service_id",
    mapping::entry::invalid_on_zero),
  mapping::entry(
    &acknowledgement::state,
    "state"),
  mapping::entry(
    &acknowledgement::notify_only_if_not_already_acknowledged,
    "notify_only_if_not_already_acknowledged"),
  mapping::entry()
};

// Operations.
static io::data* new_ack() {
  return (new acknowledgement);
}
io::event_info::event_operations const acknowledgement::operations = {
  &new_ack
};
